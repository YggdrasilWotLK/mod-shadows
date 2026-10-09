DROP TABLE IF EXISTS `shadows_dungeon_suggestion_abbrevation`;
CREATE TABLE `shadows_dungeon_suggestion_abbrevation` (
    `id`              TINYINT(3)   NOT NULL AUTO_INCREMENT UNIQUE,
    `definition_slug` VARCHAR(255) NOT NULL,
    `abbrevation`     VARCHAR(16)  NOT NULL,

    PRIMARY KEY (`id`),
    KEY `definition_slug` (`definition_slug`)
)
ENGINE=MyISAM
DEFAULT CHARSET=utf8
ROW_FORMAT=FIXED
COMMENT='Shadow dungeon suggestion abbrevations';

-- = Example =

-- INSERT INTO `shadows_dungeon_suggestion_abbrevation` VALUES

-- (NULL, 'rfc', 'Ragefire'),
-- (NULL, 'rfc', 'RFC'),
-- (NULL, 'st', 'Sunken Temple'),
-- (NULL, 'st', 'ST'),
-- (NULL, 'stocks', 'Stockades');
-- (NULL, 'stocks', 'Stockade');
