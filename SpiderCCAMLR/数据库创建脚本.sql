CREATE TABLE `OceanNews` (
  `idOecanNews` int(11) NOT NULL AUTO_INCREMENT,
  `newsTitle` varchar(150) NOT NULL,
  `newsURL` varchar(150) NOT NULL,
  `newsDate` varchar(30) NOT NULL,
  PRIMARY KEY (`idOecanNews`),
  UNIQUE KEY `newsTitle_UNIQUE` (`newsTitle`),
  UNIQUE KEY `newsURL_UNIQUE` (`newsURL`)
)