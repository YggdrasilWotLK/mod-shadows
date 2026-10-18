REVOKE ALL PRIVILEGES ON * . * FROM 'acore'@'localhost';

REVOKE ALL PRIVILEGES ON `ycore_shadows` . * FROM 'acore'@'localhost';

REVOKE GRANT OPTION ON `ycore_shadows` . * FROM 'acore'@'localhost';

DROP USER 'acore'@'localhost';

DROP DATABASE IF EXISTS `ycore_shadows`;
