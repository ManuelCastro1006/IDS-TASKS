#include <Windows.h> //lib para ventanas de windows
#include <sql.h>  //lib para reconocer comandos y consultas de sql
#include <sqlext.h>  // lib para reconocer resultados
#include <iostream>  // lib para entrada y salida de datos
#include <iomanip> //lib para dar formato dependiendo el num de caracteres para tablas

using namespace std;

int main() {
	SQLHENV hEnv; //enviroment
	SQLHDBC hDbc; //connection
	SQLRETURN ret;

	//gestor de entorno
	ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
	ret = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

	ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

	//gestor de coneccion
	ret = SQLConnect(hDbc, (SQLWCHAR*)L"IDS-test-server", SQL_NTS, (SQLWCHAR*)L"Username", SQL_NTS, (SQLWCHAR*)L"Password", SQL_NTS);
	//----------------------------------^nombre del servidor. No usar generalment el resto para no poner claves al codigo

	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
		cout << "Conectado a la BD exitosamente." << endl;

		SQLHSTMT hStmt;

		ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

		wcout << L"+-------+----------------------------+---------------------+---------------+------------+" << endl;
		wcout << L"| ID:   | Nombre completo            + Fecha_de_nacimiento + RFC           | Directivo  |" << endl;
		wcout << L"+-------+----------------------------+---------------------+---------------+------------+" << endl;

		ret = SQLExecDirect(hStmt, (SQLWCHAR*)L"SELECT * FROM empleados", SQL_NTS); //consulta a la BD

		if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
			int ID_empleado;
			SQLWCHAR Nombre[50], Apellido_paterno[50], Apellido_materno[50], Fecha_de_nacimiento[50], RFC[50], Directivo[50];

			while (SQLFetch(hStmt) == SQL_SUCCESS) {
				SQLGetData(hStmt, 1, SQL_C_LONG, &ID_empleado, 0, NULL); //ampersant (&) solo para enteros
				SQLGetData(hStmt, 2, SQL_C_WCHAR, Nombre, sizeof(Nombre), NULL); //para caracteres dar tamaño (sizeof)
				SQLGetData(hStmt, 3, SQL_C_WCHAR, Apellido_paterno, sizeof(Apellido_paterno), NULL);
				SQLGetData(hStmt, 4, SQL_C_WCHAR, Apellido_materno, sizeof(Apellido_materno), NULL);
				SQLGetData(hStmt, 5, SQL_C_WCHAR, Fecha_de_nacimiento, sizeof(Fecha_de_nacimiento), NULL);
				SQLGetData(hStmt, 6, SQL_C_WCHAR, RFC, sizeof(RFC), NULL);
				SQLGetData(hStmt, 10, SQL_C_WCHAR, Directivo, sizeof(Directivo), NULL);//el numero de hStmt es el la posicion del dato en la fila de la tabla

				// concatena 2 o mas lineas de caracteres de tipo string
				wstring nombre_completo = wstring(Nombre) + L" " + wstring(Apellido_paterno) + L" " + wstring(Apellido_materno);
				wstring dir = wstring(Directivo);
				wstring respuesta;
				if (dir == L"1") {
					respuesta = L"Si";
				}
				else {
					respuesta = L"No";
				}

				wcout << L"| " << setw(6) << left << ID_empleado
					<< L"| " << setw(27) << left << nombre_completo
					<< L"| " << setw(20) << left << Fecha_de_nacimiento
					<< L"| " << setw(14) << left << RFC
					<< L"| " << setw(11) << left << respuesta << L"|" << endl;

				
				wcout << L"+-------+----------------------------+---------------------+---------------+------------+" << endl;

			}
		}
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	else {
		cout << "Fallo la coneccion en la base de datos.";
	}

	SQLDisconnect(hDbc);
	SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

	return 0;
}