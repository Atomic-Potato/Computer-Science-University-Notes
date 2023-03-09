_Next [[🟩2 @ Triggers]]_

---
Stored procedures and functions are both types of database objects that can
be created and executed within SQL. However, there are some key differences
between the two:
- **Return value:** A `stored procedure` may or may not return a value, whereas a `function` must always return a value.
- **Usage:** A `stored procedure` is typically used to perform an action, such as modifying data or generating a report, whereas a `function` is typically used to return a value that can be used in a SQL statement.
- **Transaction control:** A `stored procedure` can participate in a transaction and can be used to control transactions, whereas a `function` cannot participate in a transaction.
- **Data modification:** A `stored procedure` can modify data in the database, whereas a `function` is typically used for read-only operations.
- **Execution context:** A `stored procedure` runs in its own execution context, whereas a `function` runs in the execution context of the statement that calls it.

# Functions
The structure of a function:
```sql
CREATE FUNCTION function_name(var1 <type>, var2 <type>, ...)
	RETURNS <type>  -- the type this function returns
BEGIN
	DECLARE var <type>, var2 <type>; -- can be omitted
	-- fill the var / do ur thing
	RETURN var;
END 
```

_For example:_
```sql
create function dept_count(dept_name varchar(20))
	returns integer
begin
	declare d_count integer;
	
	select count(*) into d_count
	from instructor
	where instructor.dept_name = dept_name
	
	return d_count; -- note that we can put the whole query
					-- after the return inside ()
					-- instead of having to create a variable
end 
```

# Stored Procedure
The structure of a procedure:
```sql
CREATE PROCEDURE procedure_name
	-- Add the parameters for the stored procedure here
	@param1 <type> = default_value,
	@param2 <type> = default_value,
AS
BEGIN
	-- Insert your statements here
END
```

To call the procedure use `exec`:
```sql
EXEC procedure_name parameter1 parameter2
```
Or using `call`
```sql
CALL procedure_name(parameter1, parameter2);
```

You can also have the procedure have multiple output parameters:
```sql
CREATE PROCEDURE procedure_name(in argument, out argument)
BEGIN
	-- do ur thing and remember to fill out the `out` arguments
END
```
This way when calling the procedure, you have to declare variables that will be filled by this procedure.