--- src/Build.OM.UnitTests/Definition/ProjectCollection_Tests.cs.orig	2021-03-27 12:05:30 UTC
+++ src/Build.OM.UnitTests/Definition/ProjectCollection_Tests.cs
@@ -1413,6 +1413,7 @@ namespace Microsoft.Build.UnitTests.OM.Definition
             Assert.True(dirtyRaised);
         }
 
+#if THISASSEMBLY
         /// <summary>
         /// Verifies that the <see cref="ProjectCollection.Version"/> is correct.
         /// </summary>
@@ -1428,6 +1429,7 @@ namespace Microsoft.Build.UnitTests.OM.Definition
             ProjectCollection.Version.Major.ShouldBe(expectedVersion.Major);
             ProjectCollection.Version.Minor.ShouldBe(expectedVersion.Minor);
         }
+#endif
 
         /// <summary>
         /// Create an empty project file and return the path
