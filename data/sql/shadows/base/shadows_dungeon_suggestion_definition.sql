
/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
DROP TABLE IF EXISTS `shadows_dungeon_suggestion_definition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `shadows_dungeon_suggestion_definition` (
  `id` tinyint NOT NULL AUTO_INCREMENT,
  `slug` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `expansion` tinyint(1) NOT NULL,
  `difficulty` tinyint(1) NOT NULL,
  `min_level` tinyint DEFAULT NULL,
  `max_level` tinyint DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=89 DEFAULT CHARSET=utf8mb3 ROW_FORMAT=FIXED COMMENT='Playerbot dungeon suggestion definitions';
/*!40101 SET character_set_client = @saved_cs_client */;

/*!40000 ALTER TABLE `shadows_dungeon_suggestion_definition` DISABLE KEYS */;
INSERT INTO `shadows_dungeon_suggestion_definition` VALUES (1,'rfc','Ragefire Chasm',0,0,15,21,NULL),(2,'dm','Deadmines',0,0,15,23,NULL),(3,'wc','Wailing Caverns',0,0,17,27,NULL),(4,'sfk','Shadowfang Keep',0,0,18,24,NULL),(5,'bfd','Blackfathom Deeps',0,0,20,27,NULL),(6,'stocks','Stormwind Stockade',0,0,22,30,NULL),(7,'gnomer','Gnomeregan',0,0,26,36,NULL),(8,'sm-gy','Scarlet Monastery: Graveyard',0,0,26,36,NULL),(9,'sm-lib','Scarlet Monastery: Library',0,0,29,39,NULL),(10,'rfk','Razorfen Kraul',0,0,32,35,NULL),(11,'sm-armory','Scarlet Monastery: Armory',0,0,32,42,NULL),(12,'sm-cath','Scarlet Monastery: Cathedral',0,0,35,45,NULL),(13,'rfd','Razorfen Downs',0,0,42,45,NULL),(14,'ulda','Uldaman',0,0,42,52,NULL),(15,'mara','Maraudon',0,0,42,52,NULL),(16,'zf','Zul\'Farrak',0,0,46,56,NULL),(17,'st','Temple of Atal\'Hakkar',0,0,50,60,NULL),(18,'brd','Blackrock Depths',0,0,52,60,NULL),(19,'dm-w','Dire Maul: West',0,0,55,60,NULL),(20,'dm-e','Dire Maul: East',0,0,55,60,NULL),(21,'dm-n','Dire Maul: North',0,0,55,60,NULL),(22,'lbrs','Lower Blackrock Spire',0,0,55,60,NULL),(23,'scholo','Scholomance',0,0,58,60,NULL),(24,'strat','Stratholme',0,0,58,60,NULL),(25,'hfr','Hellfire Ramparts',1,0,59,67,NULL),(26,'bf','The Blood Furnace',1,0,60,68,NULL),(27,'sp','The Slave Pens',1,0,61,69,NULL),(28,'ub','The Underbog',1,0,62,70,NULL),(29,'mt','Mana-Tombs',1,0,63,70,NULL),(30,'ac','Auchenai Crypts',1,0,64,70,NULL),(31,'seth','Sethekk Halls',1,0,66,70,NULL),(32,'oh','Old Hillsbrad Foothills',1,0,66,70,NULL),(33,'bm','The Black Morass',1,0,68,70,NULL),(34,'mech','The Mechanar',1,0,68,70,NULL),(35,'bot','The Botanica',1,0,69,70,NULL),(36,'arc','The Arcatraz',1,0,69,70,NULL),(37,'sh','The Shattered Halls',1,0,69,70,NULL),(38,'sv','The Steamvault',1,0,69,70,NULL),(39,'sl','Shadow Labyrinth',1,0,69,70,NULL),(40,'mgt','Magister\'s Terrace',1,0,70,70,NULL),(41,'hfr','Hellfire Ramparts',1,1,70,70,NULL),(42,'bf','The Blood Furnace',1,1,70,70,NULL),(43,'sp','The Slave Pens',1,1,70,70,NULL),(44,'ub','The Underbog',1,1,70,70,NULL),(45,'mt','Mana-Tombs',1,1,70,70,NULL),(46,'ac','Auchenai Crypts',1,1,70,70,NULL),(47,'seth','Sethekk Halls',1,1,70,70,NULL),(48,'oh','Old Hillsbrad Foothills',1,1,70,70,NULL),(49,'bm','The Black Morass',1,1,70,70,NULL),(50,'mech','The Mechanar',1,1,70,70,NULL),(51,'bot','The Botanica',1,1,70,70,NULL),(52,'arc','The Arcatraz',1,1,70,70,NULL),(53,'sh','The Shattered Halls',1,1,70,70,NULL),(54,'sv','The Steamvault',1,1,70,70,NULL),(55,'sl','Shadow Labyrinth',1,1,70,70,NULL),(56,'mgt','Magister\'s Terrace',1,1,70,70,NULL),(57,'uk','Utgarde Keep',2,0,70,72,NULL),(58,'nexus','The Nexus',2,0,71,73,NULL),(59,'an','Azjol-Nerub',2,0,72,74,NULL),(60,'ak','Ahn\'kahet: The Old Kingdom',2,0,73,75,NULL),(61,'dtk','Drak\'Tharon Keep',2,0,74,76,NULL),(62,'vh','Violet Hold',2,0,75,77,NULL),(63,'gd','Gundrak',2,0,76,78,NULL),(64,'hos','Halls of Stone',2,0,77,79,NULL),(65,'hol','Halls of Lightning',2,0,80,80,NULL),(66,'cos','The Culling of Stratholme',2,0,80,80,NULL),(67,'oculus','The Oculus',2,0,80,80,NULL),(68,'up','Utgarde Pinnacle',2,0,80,80,NULL),(69,'toc','Trial of the Champion',2,0,80,80,NULL),(70,'fos','Forge of Souls',2,0,80,80,NULL),(71,'pos','Pit of Saron',2,0,80,80,NULL),(72,'hor','Halls of Reflection',2,0,80,80,NULL),(73,'uk','Utgarde Keep',2,1,80,80,NULL),(74,'nexus','The Nexus',2,1,80,80,NULL),(75,'an','Azjol-Nerub',2,1,80,80,NULL),(76,'ak','Ahn\'kahet: The Old Kingdom',2,1,80,80,NULL),(77,'dtk','Drak\'Tharon Keep',2,1,80,80,NULL),(78,'vh','Violet Hold',2,1,80,80,NULL),(79,'gd','Gundrak',2,1,80,80,NULL),(80,'hos','Halls of Stone',2,1,80,80,NULL),(81,'hol','Halls of Lightning',2,1,80,80,NULL),(82,'cos','The Culling of Stratholme',2,1,80,80,NULL),(83,'oculus','The Oculus',2,1,80,80,NULL),(84,'up','Utgarde Pinnacle',2,1,80,80,NULL),(85,'toc','Trial of the Champion',2,1,80,80,NULL),(86,'fos','Forge of Souls',2,1,80,80,NULL),(87,'pos','Pit of Saron',2,1,80,80,NULL),(88,'hor','Halls of Reflection',2,1,80,80,NULL);
/*!40000 ALTER TABLE `shadows_dungeon_suggestion_definition` ENABLE KEYS */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

