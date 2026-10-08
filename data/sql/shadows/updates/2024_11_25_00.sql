UPDATE `updates_include`
SET `path` = '$/data/sql/shadows/updates'
WHERE `state` = 'RELEASED';

UPDATE `updates_include`
SET `path` = '$/data/sql/shadows/custom'
WHERE `state` = 'CUSTOM';

UPDATE `updates_include`
SET `path` = '$/data/sql/shadows/archive'
WHERE `state` = 'ARCHIVED';
