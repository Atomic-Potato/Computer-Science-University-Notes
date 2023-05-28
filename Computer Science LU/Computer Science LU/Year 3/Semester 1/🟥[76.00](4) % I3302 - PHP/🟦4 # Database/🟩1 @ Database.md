_Next [[🟩2 @ Using MySQLi]]_

---

# How Web Database Architectures Work
1. A user’s web browser issues an HTTP request for a particular web page. _(search)_
2. The web server receives the request, retrieves the file, and passes it to the PHP engine for processing.
3. The PHP engine begins parsing the script. Inside the script, there is a command to connect to the database and execute a query _(perform the search)_. PHP opens a connection to the MySQL server and sends on the appropriate query.
4. The MySQL server receives the database query, processes it, and sends the results back to the PHP engine.
5. The PHP engine finishes running the script. This usually involves formatting the query results nicely in HTML. It then returns the resulting HTML to the web server.
6. The web server passes the HTML back to the browser, where the user can see the result requested.

# MySQL
One of the specificities of MySQL is to be able to manage multiple engines in a single database. 
Each table can use a different engine within a database. This is to optimize the use of each table.

The most 2 important engines of MySQL are:
- `MyISAM:` Its MySQL default engine, simple, uses several files that grow as the database grows. But does not support transactions or foreign keys.
- `InnoDB:` Engine created and maintained by InnoBase. It manages transactions and foreign keys _(and therefore the integrity of its tables)_. In exchange, the bases that use it occupy much more space on the disk.

# MySQLi Extension
There are three main API options when considering connecting to a MySQL
database server:
- PHP's MySQL Extension
- PHP's MySQLi Extension
- PHP Data Objects _(PDO)_

Each has its own advantages and disadvantages.

The MySQLi _(i for improved)_ was developed to take advantage of new features found in MySQL systems versions 4.1.3 and newer.

The MySQLi extension has a number of benefits, the key enhancements over the MySQL extension being:
- Object-oriented interface
- Support for Prepared Statements
- Support for Multiple Statements
- Support for Transactions
- Enhanced debugging capabilities
- Embedded server support
As well as the object-oriented interface the extension also provides a **procedural interface.**

---

_Next [[🟩2 @ Using MySQLi]]_
