_Next [[🟩2 @ Triggers]]_

---

# Functions
The structure of a function
```sql
CREATE FUNCTION function_name(var1 <type>, var2 <type>, ...)
	RETURNS <type>  -- the type this function returns
					-- if it is void then this can be omitted
BEGIN
	DECLARE var <type>, var2 <type>; -- can be omitted
	-- fill the var / do ur thing
	RETURN var; -- is omitted if theres no RETURNS
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