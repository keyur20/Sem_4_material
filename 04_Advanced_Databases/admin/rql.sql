create database administrator;
use administrator;

create table adminis (student_id int not null, student_name varchar(40),student_age int,student_dob date not null) ENGINE = MEMORY;

select * from adminis;
drop table adminis;

Insert into adminis (student_id, student_name , student_age, student_dob)
values
(1,'keyur',20,'2002-12-20'),
(2,'tirth',19,'2003-12-20'),
(3,'krishiv',21,'2002-11-25'),
(4,'kushal',19,'2004-09-19'),
(5,'lulla',22,'2005-11-27'),
(6,'boi',18,'2002-08-01'),
(7,'lola',23,'2004-11-13'),
(8,'chinmay',19,'2002-07-11');

CREATE USER 'root'@'127.0.0.1' IDENTIFIED BY 'keyur123';
GRANT ALL ON *.* TO 'root'@'127.0.0.1';
FLUSH PRIVILEGES;
select * into outfile ' C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/adminis_data.txt' from adminis;
SELECT * INTO OUTFILE '/var/lib/mysql-files/adminis_data.txt' FROM adminis;








