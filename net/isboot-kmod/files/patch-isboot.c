--- isboot.c.orig	2015-11-05 16:50:51 UTC
+++ isboot.c
@@ -165,11 +165,11 @@ isboot_get_ifa_by_mac(uint8_t *lladdr)
 
 	IFNET_RLOCK();
 #if __FreeBSD_version >= 800500
-	TAILQ_FOREACH(ifp, &V_ifnet, if_link)
+	CK_STAILQ_FOREACH(ifp, &V_ifnet, if_link)
 #else
-	TAILQ_FOREACH(ifp, &ifnet, if_link)
+	CK_STAILQ_FOREACH(ifp, &ifnet, if_link)
 #endif
-		TAILQ_FOREACH(ifa, &ifp->if_addrhead, ifa_link) {
+		CK_STAILQ_FOREACH(ifa, &ifp->if_addrhead, ifa_link) {
 			if (ifa->ifa_addr->sa_family != AF_LINK)
 				continue;
 			if (memcmp(lladdr,
@@ -347,9 +347,9 @@ isboot_set_v4gw(struct sockaddr_in *gateway)
 	netmask.sin_addr.s_addr = htonl(0);
 
 	/* delete gateway if exists */
-	error = rtrequest(RTM_DELETE, (struct sockaddr *)&dst,
+	error = rtrequest_fib(RTM_DELETE, (struct sockaddr *)&dst,
 	    (struct sockaddr *)gateway, (struct sockaddr *)&netmask,
-	    0, NULL);
+	    0, NULL, RT_DEFAULT_FIB);
 	if (error) {
 		if (error != ESRCH) {
 			printf("rtrequest RTM_DELETE error %d\n",
@@ -359,9 +359,9 @@ isboot_set_v4gw(struct sockaddr_in *gateway)
 	}
 
 	/* set new default gateway */
-	error = rtrequest(RTM_ADD, (struct sockaddr *)&dst,
+	error = rtrequest_fib(RTM_ADD, (struct sockaddr *)&dst,
 	    (struct sockaddr *)gateway, (struct sockaddr *)&netmask,
-	    RTF_GATEWAY | RTF_STATIC, NULL);
+	    RTF_GATEWAY | RTF_STATIC, NULL, RT_DEFAULT_FIB);
 	if (error) {
 		printf("rtrequest RTM_ADD error %d\n", error);
 		return (error);
@@ -391,9 +391,9 @@ isboot_set_v6gw(struct sockaddr_in6 *gateway)
 	memset(&netmask.sin6_addr, 0, 16);
 
 	/* delete gateway if exists */
-	error = rtrequest(RTM_DELETE, (struct sockaddr *)&dst,
+	error = rtrequest_fib(RTM_DELETE, (struct sockaddr *)&dst,
 	    (struct sockaddr *)gateway, (struct sockaddr *)&netmask,
-	    0, NULL);
+	    0, NULL, RT_DEFAULT_FIB);
 	if (error) {
 		if (error != ESRCH) {
 			printf("rtrequest RTM_DELETE error %d\n",
@@ -403,9 +403,9 @@ isboot_set_v6gw(struct sockaddr_in6 *gateway)
 	}
 
 	/* set new default gateway */
-	error = rtrequest(RTM_ADD, (struct sockaddr *)&dst,
+	error = rtrequest_fib(RTM_ADD, (struct sockaddr *)&dst,
 	    (struct sockaddr *)gateway, (struct sockaddr *)&netmask,
-	    RTF_GATEWAY | RTF_STATIC, NULL);
+	    RTF_GATEWAY | RTF_STATIC, NULL, RT_DEFAULT_FIB);
 	if (error) {
 		printf("rtrequest RTM_ADD error %d\n", error);
 		return (error);
