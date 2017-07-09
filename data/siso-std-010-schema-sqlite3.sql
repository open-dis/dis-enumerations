CREATE TABLE ebv (
  title        TEXT,
  release      TEXT,
  date         DATE,
  href         TEXT,
  organisation TEXT,
  PRIMARY KEY(title, release, date, href, organisation)
);

CREATE TABLE revision (
  title        TEXT,
  date         DATE,
  CR           INTEGER,
  CR2          INTEGER,
  PRIMARY KEY(title)
);

CREATE TABLE acronym (
  id           TEXT,
  description  TEXT
);

CREATE TABLE tab (
  id           INTEGER,
  cname        TEXT,
  length       INTEGER,
  name         TEXT,
  source       TEXT,
  PRIMARY KEY(id)
);

CREATE TABLE abstract (
  abstract_id  INTEGER PRIMARY KEY,
  description  TEXT,
  footnote     TEXT,
  xref         TEXT,
  deleted      INTEGER,
  unused       INT
);

CREATE TABLE meta (
  abstract_id   INTEGER,
  id            TEXT,
  value         TEXT,
  PRIMARY KEY(abstract_id, id)
);

CREATE TABLE enum (
  table_id      INTEGER,
  bitmask_id    INTEGER,
  id            INTEGER,
  id2           INTEGER,
  abstract_id   INTEGER,
  PRIMARY KEY(table_id, bitmask_id, id, id2)
);

CREATE TABLE bitmask (
  table_id      INTEGER,
  id            INTEGER,
  id2           INTEGER,
  abstract_id   INTEGER,
  PRIMARY KEY(table_id, id, id2)
);

CREATE TABLE cet (
  table_id      INTEGER,
  kind          INTEGER,
  domain        INTEGER,
  country       INTEGER,
  category      INTEGER,
  subcategory   INTEGER,
  specific      INTEGER,
  specific2     INTEGER,
  extra         INTEGER,
  extra2        INTEGER,
  abstract_id   INTEGER,
  PRIMARY KEY(table_id, kind, domain, country, category, subcategory, specific, specific2, extra, extra2)
);

CREATE TABLE cot (
  table_id      INTEGER,
  kind          INTEGER,
  domain        INTEGER,
  category      INTEGER,
  subcategory   INTEGER,
  abstract_id   INTEGER,
  PRIMARY KEY(table_id, kind, domain, category, subcategory)
);
