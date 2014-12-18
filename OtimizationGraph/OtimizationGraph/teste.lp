/* Objective function */
min: +x1_1 +2 x1_2 +3 x1_3 +4 x2_1 +5 x2_2 +6 x2_3 +7 x3_1 +8 x3_2 +9 x3_3;

/* Constraints */
+x1_2 +x1_3 = 1;
+x2_1 +x2_3 = 1;
+x3_1 +x3_2 = 1;
+x2_1 +x3_1 = 1;
+x1_2 +x3_2 = 1;
+x1_3 +x2_3 = 1;
