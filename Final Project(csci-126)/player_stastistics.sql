create table player_statistics(
pid INT NOT NULL,
FOREIGN KEY(pid) REFERENCES player(pid),
name TEXT NOT NULL,
age  INT NOT NULL,
height DOUBLE NOT NULL,
weight DOUBLE NOT NULL,
gp INT NULL,
pts DOUBLE NULL,
reb DOUBLE NULL,
ast DOUBLE NULL,
net_rating DOUBLE NULL,
season TEXT
);