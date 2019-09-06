# Simple Database Management System

## Description

This project aims to create a simple database management system which will be able to execute basic DDL and DML operations.

## How to Run

In order to build the project, `cmake` must be installed. After installing cmake, run the following in the project's root directory to build the project:

```
cmake . && make
```

Execute the following command to use the program interactively:

```
./database_management_system
```

Also you can give the query commands to the program in an input file and print the outputs to an output file as follows:

```
./database_management_system input.txt output.txt
```

## Instructions

Available commands are listed below:

### DDL (Data Definition Language) Operations

Create Type:
```
create type <type-name> <number-of-fields> <field1-name> <field2-name> ...
```

Delete Type:
```
delete type <type-name>
```

List All Types:
```
list type
```

### DML (Data Manipulation Language) Operations

Create Record:
```
create record <type-name> <field1-value> <field2-value> ...
```

Delete Record:
```
delete record <type-name> <primary-key>
```

Update Record:
```
update record <type-name> <primary-key> <field2-value> <field3-value> ...
```

Search Record:
```
search record <type-name> <primary-key>
```

List All Records:
```
list record <type-name>
```
