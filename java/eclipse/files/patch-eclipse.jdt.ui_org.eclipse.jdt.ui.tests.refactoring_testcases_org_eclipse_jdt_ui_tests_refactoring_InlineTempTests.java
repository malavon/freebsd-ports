--- eclipse.jdt.ui/org.eclipse.jdt.ui.tests.refactoring/test cases/org/eclipse/jdt/ui/tests/refactoring/InlineTempTests.java.orig	2026-02-13 14:44:27 UTC
+++ eclipse.jdt.ui/org.eclipse.jdt.ui.tests.refactoring/test cases/org/eclipse/jdt/ui/tests/refactoring/InlineTempTests.java
@@ -1,5 +1,5 @@
 /*******************************************************************************
- * Copyright (c) 2000, 2020 IBM Corporation and others.
+ * Copyright (c) 2000, 2025 IBM Corporation and others.
  *
  * This program and the accompanying materials
  * are made available under the terms of the Eclipse Public License 2.0
@@ -419,6 +419,90 @@ public class InlineTempTests extends GenericRefactorin
 		helper1(4, 14, 4, 15);
 	}
 
+	@Test
+	public void test53() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(12, 13, 12, 14);
+	}
+
+	@Test
+	public void test54() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(7, 13, 7, 14);
+	}
+
+	@Test
+	public void test55() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(11, 13, 11, 14);
+	}
+
+	@Test
+	public void test56() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(12, 13, 12, 14);
+	}
+
+	@Test
+	public void test57() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(9, 26, 9, 27);
+	}
+
+	@Test
+	public void test58() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(9, 26, 9, 27);
+	}
+
+	@Test
+	public void test59() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(11, 11, 11, 12);
+	}
+
+	@Test
+	public void test60() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(7, 13, 7, 14);
+	}
+
+	@Test
+	public void test61() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(9, 13, 9, 14);
+	}
+
+	@Test
+	public void test62() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(14, 13, 14, 14);
+	}
+
+	@Test
+	public void test63() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(11, 13, 11, 14);
+	}
+
+	@Test
+	public void test64() throws Exception {
+		//https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536
+		helper1(7, 13, 7, 14);
+	}
+
+	@Test
+	public void test65() throws Exception {
+		//https://github.com/eclipse-jdt/eclipse.jdt.ui/issues/1705
+		helper1(6, 13, 6, 19);
+	}
+
+	@Test
+	public void test66() throws Exception {
+		//https://github.com/eclipse-jdt/eclipse.jdt.ui/issues/1859
+		helper1(18, 13, 18, 21);
+	}
+
 	//------
 
 	@Ignore("compile errors are ok now")
@@ -503,6 +587,11 @@ public class InlineTempTests extends GenericRefactorin
 	@Test
 	public void testFail14() throws Exception {
 		helper2(5, 17, 5, 18);
+	}
+
+	@Ignore("https://bugs.eclipse.org/bugs/show_bug.cgi?id=367536")
+	public void testFail15() throws Exception {
+		helper2(12, 13, 12, 14);
 	}
 
 }
