**A cursor is a mechanism you can use to fetch rows one at a time.** _(When you write code for a transaction where the result set includes several rows of data, you must declare and use a cursor.)_

A cursor is an entity that maps over a result set and establishes a position on a single row within the result set.

After the cursor is positioned on a row, operations can be performed on that row, or on a block of rows starting at that position.
_The most common operation is to `FETCH` (retrieve) the current row or block of rows._

# Declaring And Using a Cursor
```sql
-- Declaration
DECLARE cursor_name CURSOR
FOR
	-- select statement

-- Usage
OPEN cursor_name
FETCH NEXT FROM cursor_name
-- Closing and removing the cursor
CLOSE cursor_name
DEALLOCATE cursor_name
```

# Storing Results
```sql
-- First declare the variables
DECLARE @variable_name <variable-type>, @variable_name2 <variable-type>, ...

-- Storing results of a cursor into the variables
FETCH NEXT FROM cursor_name INTO @variable_name, @variable_name2
```

# Looping over a cursor
```sql
OPEN cursor_name
	FETCH NEXT FROM cursor_name
	WHILE @@FETCH_STATUS = 0    -- Fetch status is a global variable 
								-- that is 0 when theres no data that got fetched
	BEGIN
		-- do ur thing ma boy
		FETCH NEXT FROM cursor_name
	END
```

# _Example_
```sql
DECLARE @sid varchar(5), @sfname varchar(20), @slname varchar(40), …

DECLARE st_cursor CURSOR
FOR
	SELECT sid, sfname, slname
	FROM student
	WHERE …
	
OPEN st_cursor
	FETCH NEXT FROM st_cursor INTO @sid, @sfname, @slname
	WHILE @@FETCH_STATUS = 0
	BEGIN
		…
		SELECT …
		--Get the next student.
		FETCH NEXT FROM st_cursor INTO @sid, @sfname, @slname
	END
CLOSE st_cursor
DEALLOCATE st_cursor
GO
```