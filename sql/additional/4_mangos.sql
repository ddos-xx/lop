DELETE FROM spell_proc_event WHERE entry IN (49188,56822,59057);
INSERT INTO `spell_proc_event` VALUES (49188, 0, 15, 0, 0x20000, 0, 0, 0, 0, 0, 0);
INSERT INTO `spell_chain` VALUES (49188, 0, 49188, 1, 0);
INSERT INTO `spell_chain` VALUES (56822, 49188, 49188, 2, 0);
INSERT INTO `spell_chain` VALUES (59057, 56822, 49188, 3, 0);