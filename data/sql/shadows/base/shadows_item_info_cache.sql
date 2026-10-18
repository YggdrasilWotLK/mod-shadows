
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
DROP TABLE IF EXISTS `shadows_item_info_cache`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `shadows_item_info_cache` (
  `id` int NOT NULL,
  `quality` int DEFAULT NULL,
  `slot` int DEFAULT NULL,
  `source` bigint DEFAULT NULL,
  `sourceId` bigint DEFAULT NULL,
  `team` bigint DEFAULT NULL,
  `faction` bigint DEFAULT NULL,
  `factionRepRank` bigint DEFAULT NULL,
  `minLevel` bigint DEFAULT NULL,
  `scale_1` bigint DEFAULT NULL,
  `scale_2` bigint DEFAULT NULL,
  `scale_3` bigint DEFAULT NULL,
  `scale_4` bigint DEFAULT NULL,
  `scale_5` bigint DEFAULT NULL,
  `scale_6` bigint DEFAULT NULL,
  `scale_7` bigint DEFAULT NULL,
  `scale_8` bigint DEFAULT NULL,
  `scale_9` bigint DEFAULT NULL,
  `scale_10` bigint DEFAULT NULL,
  `scale_11` bigint DEFAULT NULL,
  `scale_12` bigint DEFAULT NULL,
  `scale_13` bigint DEFAULT NULL,
  `scale_14` bigint DEFAULT NULL,
  `scale_15` bigint DEFAULT NULL,
  `scale_16` bigint DEFAULT NULL,
  `scale_17` bigint DEFAULT NULL,
  `scale_18` bigint DEFAULT NULL,
  `scale_19` bigint DEFAULT NULL,
  `scale_20` bigint DEFAULT NULL,
  `scale_21` bigint DEFAULT NULL,
  `scale_22` bigint DEFAULT NULL,
  `scale_23` bigint DEFAULT NULL,
  `scale_24` bigint DEFAULT NULL,
  `scale_25` bigint DEFAULT NULL,
  `scale_26` bigint DEFAULT NULL,
  `scale_27` bigint DEFAULT NULL,
  `scale_28` bigint DEFAULT NULL,
  `scale_29` bigint DEFAULT NULL,
  `scale_30` bigint DEFAULT NULL,
  `scale_31` bigint DEFAULT NULL,
  `scale_32` bigint DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb3 ROW_FORMAT=FIXED COMMENT='PlayerbotAI item info Cache';
/*!40101 SET character_set_client = @saved_cs_client */;

/*!40000 ALTER TABLE `shadows_item_info_cache` DISABLE KEYS */;
/*!40000 ALTER TABLE `shadows_item_info_cache` ENABLE KEYS */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

