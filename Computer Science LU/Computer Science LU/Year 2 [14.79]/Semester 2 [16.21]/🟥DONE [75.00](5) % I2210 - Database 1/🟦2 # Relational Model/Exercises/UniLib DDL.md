```sql
USE master
GO

CREATE DATABASE UniLib
	ON(NAME = \UniLib_dat, FILENAME = 'C:\...\UniLib.mdf')
	LOG ON(NAME = '\UniLib_log', FILENAME = 'C:\...\UniLib.ldf')
go

create table Teachers
(
	teachid char(6) not null,
	name varchar(30) null,
	phone varchar(30) null,
	email varchar(30) null,
	address varchar(30) null,

	primary key(teachid)
)
go

create table Students
(
	studid char(6) not null,
	name varchar(30) null,
	phone varchar(30) null,
	email varchar(30) null,
	address varchar(30) null,

	primary key(studid)
)
go


create table Publishers
(
	pubid char(6) not null,
	pubName varchar(30) null,
	pubAddress varchar(30) null,

	primary key(pubid)
)
go

create table Books
(
	bookid char(6) not null,
	pubid char(10) not null,
	title varchar(50) null,
	nbOfPages int null,
	keyWords varchar(200) null,
	bookLang varchar(5) null,
	publishingDate datetime null,

	primary key(bookid),
	foreign key(pubid) references Publishers(pubid)
)
go

create table Authors
(
	authid char(6) not null,
	authName varchar(30) null,
	nationality varchar(30) null,
	domains varchar(30) null,

	primary key(authid)
)
go


create table Borrowings
(
	borrowId char(6) not null,
	student char(6) null,
	treacher char(6) null,
	book char(6) not null,
	borrowFrom datetime,
	borrowtill datetime,

	primary key(borrowId),
	foreign key(student) references Students(studid),
	foreign key(teacher) references Teachers(teachid),
	foreign key(book) references Books(bookid)
)

create table BookAuthor
(
	book char(6) not null,
	author char(6) not null,

	primary key(book, author),
	foreign key(book) references Books(bookid),
	foreign key(author) references Authors(authid)
)
```