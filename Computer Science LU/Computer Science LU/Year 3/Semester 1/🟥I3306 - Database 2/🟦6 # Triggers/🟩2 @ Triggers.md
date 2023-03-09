_Previous [[🟩1 @ Stored Procedures & Functions]]_

---

In SQL, a trigger is a special type of stored procedure that is automatically executed in response to certain database events, such as an `insert`, `update`, or `delete` operation.

The structure of a trigger:
```sql
CREATE TRIGGER trigger_name
ON table_name -- the table that activates the trigger
AFTER <operation> -- such as delete or insert
AS
BEGIN
	-- do ur thing
END
```

# _EXAMPLE_
```sql
--preventing the insertion of a reservation for a boat that does not exist in the "Boats" table
CREATE TRIGGER tr_Reservations_Insert
ON Reservations
INSTEAD OF INSERT
AS
BEGIN
	SET NOCOUNT ON;
	DECLARE @BID INT;
	SELECT @BID = bid FROM inserted;
	
	IF NOT EXISTS (SELECT * FROM Boats WHERE bid = @BID)
	BEGIN
		RAISERROR('Boat with ID %d does not exist', 16, 1, @BID);
		RETURN;
	END
	
	INSERT INTO Reservations (sid, bid, resDate)
	SELECT sid, bid, resDate
	FROM inserted;
END;
```