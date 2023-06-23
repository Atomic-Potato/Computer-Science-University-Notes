**JDBC is a standard Java API for database independent connectivity between the Java programming language, and a wide range of databases.**

The JDBC library includes APIs for each of the tasks mentioned below that are commonly associated with database usage:
- Making a connection to a database.
- Creating SQL or MySQL statements.
- Executing SQL or MySQL queries in the database.
- Viewing & Modifying the resulting records.

# Architecture
In general, the `JDBC API` uses a `driver manager` and database-specific drivers to provide transparent connectivity to heterogeneous databases.

The `JDBC driver manager` ensures that the correct driver is used to access each data source. 

Any request like `SQL` queries from the Java based application is sent to the `JDBC driver` using `JDBC API`. The `JDBC driver` communicate with the required `DBMS` product by converting the `SQL` queries into a meaningful form so that the `DBMS` product can understand for replying the request.

## Architecture Diagram
Following is the architectural diagram, which shows the location of the driver manager with respect to the JDBC drivers and the Java application:
![[Pasted image 20230220183008.png|600]]

## Common JDBC Components
The JDBC API provides the following interfaces and classes:
- `DriverManager:` This class manages a list of database drivers.
- `Driver:` This interface handles the communications with the database server.
- `Connection:` This interface with all methods for contacting a database.
- `Statement:` You use objects created from this interface to submit the SQL statements to the database.
- `ResultSet:` These objects hold data retrieved from a database after you execute an SQL query using Statement objects
- `SQLException:` This class handles any errors that occur in a database application.

## JDBC API
JDBC API is defined in the following packages: `java.sql` and `javax.sql`

Key classes:
- `Java.sql.DriverManager`
- `Java.sql.Connection`
- `Java.sql.Statement`
- `Java.sql.ResultSet`

# Development process

## 1.  Get a connection to database
In order to connect to database you need a connection string in form of JDBC URL

Basic syntax:
```java
jdbc:<driver protocol>:<driver connection details>
```

_For example:_
```java
 jdbc:mysql://localhost:3306/mydata
```
The following is a code snipper for connecting to MySQL
![[Pasted image 20230220184143.png|600]]
Failure to connect will throw an exception:
- `java.sql.SQLException`: bad URL or credentials
- `java.lang.ClassNotFoundException`: JDBC driver not in class path

## 2. Create a Statement Object
The `Statement` object is based on connection. It will be used in later steps to execute an SQL query.
![[Pasted image 20230220184413.png | 600]]

## 3. Execute SQL query
Pass in your SQL Query using the `executeQuery()` function of a `Statement` object.
This function returns a `ResultSet` _(i.e. query result)_
![[Pasted image 20230220184635.png|600]]


## 4. Process Result Set
`ResultSet` has a results table row index, initially this index points at the row before the first one _(im guessing the titles of the columns)_.

To increment the row index once, we use the `ResultSet.next()`. _(Returns true if there are more rows to process)_
![[Pasted image 20230220185128.png|600]]

To get the content/data of the row we use `ResultSet.getX("column_name")` where **X** is the data type of that column.
![[Pasted image 20230220185244.png|600]]
