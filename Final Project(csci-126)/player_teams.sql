create table player_teams(
pid INT NOT NULL,
FOREIGN KEY(pid) REFERENCES player(pid),
tid INT NOT NULL,
FOREIGN KEY(tid) REFERENCES team(tid),
season TEXT NOT NULL)