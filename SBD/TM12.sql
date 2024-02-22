CREATE TABLE Employee (
    FirstName VARCHAR(255),
    Initial VARCHAR(1),
    LastName VARCHAR(255),
    KTPID INT PRIMARY KEY,
    Address VARCHAR(255),
    Salary DECIMAL(10, 2),
    Sex CHAR(1),
    KTPID_MGR INT,
    DNO INT
);

CREATE TABLE Department (
    DName VARCHAR(255),
    DNum INT PRIMARY KEY,
    KTPID_MGR INT,
    StartDate_MGR DATE
);

CREATE TABLE DEPARTMENTLOCATION (
    DNO INT,
    DLocation VARCHAR(255)
);

CREATE TABLE Project (
    PName VARCHAR(255),
    PNum INT PRIMARY KEY,
    PLocation VARCHAR(255),
    DNO INT
);

CREATE TABLE WorkOn (
    KTPID INT,
    PNO INT,
    LengthOfWork INT,
    FOREIGN KEY (KTPID) REFERENCES Employee(KTPID),
    FOREIGN KEY (PNO) REFERENCES Project(PNum)
);

CREATE TABLE Dependents (
    KTPID INT,
    DependentsName VARCHAR(255),
    Sex CHAR(1),
    BirthDate DATE,
    Relationship VARCHAR(255),
    FOREIGN KEY (KTPID) REFERENCES Employee(KTPID)
);

INSERT INTO Employee (FirstName, Initial, LastName, KTPID, Address, Salary, Sex, KTPID_MGR, DNO)
VALUES
    ('John', 'B', 'Smith', 123456789, '731 Fondren, Houston, TX', 30000, 'M', 333445555, 5),
    ('Franklin', 'T', 'Wong', 333445555, '638 Voss, Houston, TX', 40000, 'M', 888665555, 5),
    ('Alicia', 'J', 'Zelaya', 999887777, '3321 Castle, Spring, TX', 25000, 'F', 987654321, 4),
    ('Jennifer', 'S', 'Wallace', 987654321, '291 Berry, Bellaire, TX', 43000, 'F', 888665555, 4),
    ('Ramesh', 'K', 'Narayan', 666884444, '975 Fire Oak, Humble, TX', 38000, 'M', 333445555, 5),
    ('Joyce', 'A', 'English', 453453453, '5631 Rice, Houston, TX', 25000, 'F', 333445555, 5),
    ('Ahmad', 'V', 'Jabbar', 987987987, '980 Dallas, Houston, TX', 25000, 'M', 987654321, 4),
    ('James', 'E', 'Borg', 888665555, '450 Stone, Houston, TX', 55000, 'M', NULL, 1);

INSERT INTO Department (DName, DNum, KTPID_MGR, StartDate_MGR)
VALUES
    ('Research', 5, 333445555, '1988-05-22'),
    ('Administration', 4, 987654321, '1995-01-01'),
    ('HeadQuarters', 1, 888665555, '1981-06-19');

INSERT INTO DEPARTMENTLOCATION (DNO, DLocation)
VALUES
    (1, 'Houston'),
    (4, 'Stafford'),
    (5, 'Bellaire'),
    (5, 'Sugarland'),
    (5, 'Houston');

INSERT INTO Project (PName, PNum, PLocation, DNO)
VALUES
    ('ProductX', 1, 'Bellaire', 5),
    ('ProductY', 2, 'Sugarland', 5),
    ('ProductZ', 3, 'Houston', 5),
    ('Computerization', 10, 'Stafford', 4),
    ('Reorganization', 20, 'Houston', 1),
    ('Newbenefits', 30, 'Stafford', 4);

INSERT INTO Dependents (KTPID, DependentsName, Sex, BirthDate, Relationship)
VALUES
    (333445555, 'Alice', 'F', '1986-04-05', 'Daughter'),
    (333445555, 'Theodore', 'M', '1983-10-25', 'Son'),
    (333445555, 'Joy', 'F', '1958-05-03', 'Partner'),
    (987654321, 'Abner', 'M', '1942-02-28', 'Partner'),
    (123456789, 'Michael', 'M', '1988-01-04', 'Son'),
    (123456789, 'Alice', 'F', '1988-12-30', 'Daughter'),
    (123456789, 'Elizabeth', 'F', '1967-05-05', 'Partner');

INSERT INTO WorkOn (KTPID, PNO, LengthOfWork)
VALUES
    (123456789, 1, 32.5),
    (123456789, 2, 7.5),
    (666884444, 3, 40.0),
    (453453453, 1, 20.0),
    (453453453, 2, 20.0),
    (333445555, 2, 10.0),
    (333445555, 3, 10.0),
    (333445555, 10, 10.0),
    (333445555, 20, 10.0),
    (999887777, 30, 30.0),
    (999887777, 30, 10.0),
    (987987987, 10, 35.0),
    (987987987, 30, 5.0),
    (987654321, 30, 20.0),
    (987654321, 20, 15.0),
    (888665555, 20, NULL);
	

select FirstName, LastName, Address, Salary from Employee;

select * from Employee;

select firstname, lastname, address, ktpid from Employee where 
KTPID_MGR in (
	select KTPID from Employee
);

create table dupe as select firstname, lastname, address, ktpid from Employee where 
KTPID_MGR in (
	select KTPID from Employee
);

select * from dupe

CREATE TABLE employee_dupe AS SELECT * FROM employee;
INSERT INTO employee_dupe SELECT * FROM employee;

select employee.firstname, employee.lastname, employee.ktpid, employee.ktpid_mgr, dupe.firstname, dupe.lastname, dupe.ktpid from employee
join dupe on employee.ktpid_mgr = dupe.ktpid

select firstname, lastname, address, ktpid from employee where dno = 4

select firstname, lastname, address, ktpid from employee where ktpid in (333445555, 666884444)

select pname from project where plocation = 'Houston' or plocation = 'Stafford'

select pname, plocation from project where pnum in (1, 2)

select firstname, lastname, address from employee where salary < 40000 and sex = 'M'

select firstname, lastname, salary from employee where dno = 4