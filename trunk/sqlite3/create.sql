BEGIN TRANSACTION;
CREATE TABLE employee(id integer primary key,name text);
INSERT INTO "employee" VALUES(1,'qq');
INSERT INTO "employee" VALUES(2,'ww');
INSERT INTO "employee" VALUES(3,'ee');
INSERT INTO "employee" VALUES(4,'rr');
COMMIT;
