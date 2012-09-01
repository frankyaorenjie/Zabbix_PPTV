CREATE TABLE slideshows (
	slideshowid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(255)		DEFAULT ''	NOT NULL,
	delay		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (slideshowid)
);
CREATE TABLE slides (
	slideid		bigint		DEFAULT '0'	NOT NULL,
	slideshowid		bigint		DEFAULT '0'	NOT NULL,
	screenid		bigint		DEFAULT '0'	NOT NULL,
	step		integer		DEFAULT '0'	NOT NULL,
	delay		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (slideid)
);
CREATE INDEX slides_slides_1 on slides (slideshowid);
CREATE TABLE drules (
	druleid		bigint		DEFAULT '0'	NOT NULL,
	proxy_hostid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(255)		DEFAULT ''	NOT NULL,
	iprange		varchar(255)		DEFAULT ''	NOT NULL,
	delay		integer		DEFAULT '0'	NOT NULL,
	nextcheck		integer		DEFAULT '0'	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	unique_dcheckid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (druleid)
);
CREATE TABLE dchecks (
	dcheckid		bigint		DEFAULT '0'	NOT NULL,
	druleid		bigint		DEFAULT '0'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	key_		varchar(255)		DEFAULT '0'	NOT NULL,
	snmp_community		varchar(255)		DEFAULT '0'	NOT NULL,
	ports		varchar(255)		DEFAULT '0'	NOT NULL,
	snmpv3_securityname		varchar(64)		DEFAULT ''	NOT NULL,
	snmpv3_securitylevel		integer		DEFAULT '0'	NOT NULL,
	snmpv3_authpassphrase		varchar(64)		DEFAULT ''	NOT NULL,
	snmpv3_privpassphrase		varchar(64)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (dcheckid)
);
CREATE INDEX dchecks_1 on dchecks (druleid);
CREATE TABLE dhosts (
	dhostid		bigint		DEFAULT '0'	NOT NULL,
	druleid		bigint		DEFAULT '0'	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	lastup		integer		DEFAULT '0'	NOT NULL,
	lastdown		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (dhostid)
);
CREATE INDEX dhosts_1 on dhosts (druleid);
CREATE TABLE dservices (
	dserviceid		bigint		DEFAULT '0'	NOT NULL,
	dhostid		bigint		DEFAULT '0'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	key_		varchar(255)		DEFAULT '0'	NOT NULL,
	value		varchar(255)		DEFAULT '0'	NOT NULL,
	port		integer		DEFAULT '0'	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	lastup		integer		DEFAULT '0'	NOT NULL,
	lastdown		integer		DEFAULT '0'	NOT NULL,
	dcheckid		bigint		DEFAULT '0'	NOT NULL,
	ip		varchar(39)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (dserviceid)
);
CREATE UNIQUE INDEX dservices_1 on dservices (dcheckid,type,key_,ip,port);
CREATE INDEX dservices_2 on dservices (dhostid);
CREATE TABLE ids (
	nodeid		integer		DEFAULT '0'	NOT NULL,
	table_name		varchar(64)		DEFAULT ''	NOT NULL,
	field_name		varchar(64)		DEFAULT ''	NOT NULL,
	nextid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (nodeid,table_name,field_name)
);
CREATE TABLE httptest (
	httptestid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(64)		DEFAULT ''	NOT NULL,
	applicationid		bigint		DEFAULT '0'	NOT NULL,
	lastcheck		integer		DEFAULT '0'	NOT NULL,
	nextcheck		integer		DEFAULT '0'	NOT NULL,
	curstate		integer		DEFAULT '0'	NOT NULL,
	curstep		integer		DEFAULT '0'	NOT NULL,
	lastfailedstep		integer		DEFAULT '0'	NOT NULL,
	delay		integer		DEFAULT '60'	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	macros		varchar(2048)		DEFAULT ''	NOT NULL,
	agent		varchar(255)		DEFAULT ''	NOT NULL,
	time		decfloat(16)		DEFAULT '0'	NOT NULL,
	error		varchar(255)		DEFAULT ''	NOT NULL,
	authentication		integer		DEFAULT '0'	NOT NULL,
	http_user		varchar(64)		DEFAULT ''	NOT NULL,
	http_password		varchar(64)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (httptestid)
);
CREATE INDEX httptest_httptest_1 on httptest (applicationid);
CREATE INDEX httptest_2 on httptest (name);
CREATE INDEX httptest_3 on httptest (status);
CREATE TABLE httpstep (
	httpstepid		bigint		DEFAULT '0'	NOT NULL,
	httptestid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(64)		DEFAULT ''	NOT NULL,
	no		integer		DEFAULT '0'	NOT NULL,
	url		varchar(255)		DEFAULT ''	NOT NULL,
	timeout		integer		DEFAULT '30'	NOT NULL,
	posts		varchar(2048)		DEFAULT ''	NOT NULL,
	required		varchar(255)		DEFAULT ''	NOT NULL,
	status_codes		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (httpstepid)
);
CREATE INDEX httpstep_httpstep_1 on httpstep (httptestid);
CREATE TABLE httpstepitem (
	httpstepitemid		bigint		DEFAULT '0'	NOT NULL,
	httpstepid		bigint		DEFAULT '0'	NOT NULL,
	itemid		bigint		DEFAULT '0'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (httpstepitemid)
);
CREATE UNIQUE INDEX httpstepitem_httpstepitem_1 on httpstepitem (httpstepid,itemid);
CREATE TABLE httptestitem (
	httptestitemid		bigint		DEFAULT '0'	NOT NULL,
	httptestid		bigint		DEFAULT '0'	NOT NULL,
	itemid		bigint		DEFAULT '0'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (httptestitemid)
);
CREATE UNIQUE INDEX httptestitem_httptestitem_1 on httptestitem (httptestid,itemid);
CREATE TABLE nodes (
	nodeid		integer		DEFAULT '0'	NOT NULL,
	name		varchar(64)		DEFAULT '0'	NOT NULL,
	timezone		integer		DEFAULT '0'	NOT NULL,
	ip		varchar(39)		DEFAULT ''	NOT NULL,
	port		integer		DEFAULT '10051'	NOT NULL,
	slave_history		integer		DEFAULT '30'	NOT NULL,
	slave_trends		integer		DEFAULT '365'	NOT NULL,
	nodetype		integer		DEFAULT '0'	NOT NULL,
	masterid		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (nodeid)
);
CREATE TABLE node_cksum (
	nodeid		integer		DEFAULT '0'	NOT NULL,
	tablename		varchar(64)		DEFAULT ''	NOT NULL,
	recordid		bigint		DEFAULT '0'	NOT NULL,
	cksumtype		integer		DEFAULT '0'	NOT NULL,
	cksum		varchar(2048)		DEFAULT ''	NOT NULL,
	sync		varchar(128)		DEFAULT ''	NOT NULL
);
CREATE INDEX node_cksum_1 on node_cksum (nodeid,cksumtype,tablename,recordid);
CREATE TABLE services_times (
	timeid		bigint		DEFAULT '0'	NOT NULL,
	serviceid		bigint		DEFAULT '0'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	ts_from		integer		DEFAULT '0'	NOT NULL,
	ts_to		integer		DEFAULT '0'	NOT NULL,
	note		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (timeid)
);
CREATE INDEX services_times_times_1 on services_times (serviceid,type,ts_from,ts_to);
CREATE TABLE alerts (
	alertid		bigint		DEFAULT '0'	NOT NULL,
	actionid		bigint		DEFAULT '0'	NOT NULL,
	eventid		bigint		DEFAULT '0'	NOT NULL,
	userid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	mediatypeid		bigint		DEFAULT '0'	NOT NULL,
	sendto		varchar(100)		DEFAULT ''	NOT NULL,
	subject		varchar(255)		DEFAULT ''	NOT NULL,
	message		varchar(2048)		DEFAULT ''	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	retries		integer		DEFAULT '0'	NOT NULL,
	error		varchar(128)		DEFAULT ''	NOT NULL,
	nextcheck		integer		DEFAULT '0'	NOT NULL,
	esc_step		integer		DEFAULT '0'	NOT NULL,
	alerttype		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (alertid)
);
CREATE INDEX alerts_1 on alerts (actionid);
CREATE INDEX alerts_2 on alerts (clock);
CREATE INDEX alerts_3 on alerts (eventid);
CREATE INDEX alerts_4 on alerts (status,retries);
CREATE INDEX alerts_5 on alerts (mediatypeid);
CREATE INDEX alerts_6 on alerts (userid);
CREATE TABLE history (
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	value		decfloat(16)		DEFAULT '0.0000'	NOT NULL
);
CREATE INDEX history_1 on history (itemid,clock);
CREATE TABLE history_sync (
	id		bigint			NOT NULL	GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1),
	nodeid		bigint		DEFAULT '0'	NOT NULL,
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	value		decfloat(16)		DEFAULT '0.0000'	NOT NULL,
	PRIMARY KEY (id)
);
CREATE INDEX history_sync_1 on history_sync (nodeid,id);
CREATE TABLE history_uint (
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	value		bigint		DEFAULT '0'	NOT NULL
);
CREATE INDEX history_uint_1 on history_uint (itemid,clock);
CREATE TABLE history_uint_sync (
	id		bigint			NOT NULL	GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1),
	nodeid		bigint		DEFAULT '0'	NOT NULL,
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	value		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (id)
);
CREATE INDEX history_uint_sync_1 on history_uint_sync (nodeid,id);
CREATE TABLE history_str (
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	value		varchar(255)		DEFAULT ''	NOT NULL
);
CREATE INDEX history_str_1 on history_str (itemid,clock);
CREATE TABLE history_str_sync (
	id		bigint			NOT NULL	GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1),
	nodeid		bigint		DEFAULT '0'	NOT NULL,
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	value		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (id)
);
CREATE INDEX history_str_sync_1 on history_str_sync (nodeid,id);
CREATE TABLE history_log (
	id		bigint		DEFAULT '0'	NOT NULL,
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	timestamp		integer		DEFAULT '0'	NOT NULL,
	source		varchar(64)		DEFAULT ''	NOT NULL,
	severity		integer		DEFAULT '0'	NOT NULL,
	value		varchar(2048)		DEFAULT ''	NOT NULL,
	logeventid		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (id)
);
CREATE INDEX history_log_1 on history_log (itemid,clock);
CREATE UNIQUE INDEX history_log_2 on history_log (itemid,id);
CREATE TABLE history_text (
	id		bigint		DEFAULT '0'	NOT NULL,
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	value		varchar(2048)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (id)
);
CREATE INDEX history_text_1 on history_text (itemid,clock);
CREATE UNIQUE INDEX history_text_2 on history_text (itemid,id);
CREATE TABLE proxy_history (
	id		bigint			NOT NULL	GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1),
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	timestamp		integer		DEFAULT '0'	NOT NULL,
	source		varchar(64)		DEFAULT ''	NOT NULL,
	severity		integer		DEFAULT '0'	NOT NULL,
	value		varchar(2048)		DEFAULT ''	NOT NULL,
	logeventid		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (id)
);
CREATE INDEX proxy_history_1 on proxy_history (clock);
CREATE TABLE proxy_dhistory (
	id		bigint			NOT NULL	GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1),
	clock		integer		DEFAULT '0'	NOT NULL,
	druleid		bigint		DEFAULT '0'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	ip		varchar(39)		DEFAULT ''	NOT NULL,
	port		integer		DEFAULT '0'	NOT NULL,
	key_		varchar(255)		DEFAULT ''	NOT NULL,
	value		varchar(255)		DEFAULT ''	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	dcheckid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (id)
);
CREATE INDEX proxy_dhistory_1 on proxy_dhistory (clock);
CREATE TABLE events (
	eventid		bigint		DEFAULT '0'	NOT NULL,
	source		integer		DEFAULT '0'	NOT NULL,
	object		integer		DEFAULT '0'	NOT NULL,
	objectid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	value		integer		DEFAULT '0'	NOT NULL,
	acknowledged		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (eventid)
);
CREATE INDEX events_1 on events (object,objectid,eventid);
CREATE INDEX events_2 on events (clock);
CREATE TABLE trends (
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	num		integer		DEFAULT '0'	NOT NULL,
	value_min		decfloat(16)		DEFAULT '0.0000'	NOT NULL,
	value_avg		decfloat(16)		DEFAULT '0.0000'	NOT NULL,
	value_max		decfloat(16)		DEFAULT '0.0000'	NOT NULL,
	PRIMARY KEY (itemid,clock)
);
CREATE TABLE trends_uint (
	itemid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	num		integer		DEFAULT '0'	NOT NULL,
	value_min		bigint		DEFAULT '0'	NOT NULL,
	value_avg		bigint		DEFAULT '0'	NOT NULL,
	value_max		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (itemid,clock)
);
CREATE TABLE acknowledges (
	acknowledgeid		bigint		DEFAULT '0'	NOT NULL,
	userid		bigint		DEFAULT '0'	NOT NULL,
	eventid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	message		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (acknowledgeid)
);
CREATE INDEX acknowledges_1 on acknowledges (userid);
CREATE INDEX acknowledges_2 on acknowledges (eventid);
CREATE INDEX acknowledges_3 on acknowledges (clock);
CREATE TABLE auditlog (
	auditid		bigint		DEFAULT '0'	NOT NULL,
	userid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	action		integer		DEFAULT '0'	NOT NULL,
	resourcetype		integer		DEFAULT '0'	NOT NULL,
	details		varchar(128) 		DEFAULT '0'	NOT NULL,
	ip		varchar(39)		DEFAULT ''	NOT NULL,
	resourceid		bigint		DEFAULT '0'	NOT NULL,
	resourcename		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (auditid)
);
CREATE INDEX auditlog_1 on auditlog (userid,clock);
CREATE INDEX auditlog_2 on auditlog (clock);
CREATE TABLE auditlog_details (
	auditdetailid		bigint		DEFAULT '0'	NOT NULL,
	auditid		bigint		DEFAULT '0'	NOT NULL,
	table_name		varchar(64)		DEFAULT ''	NOT NULL,
	field_name		varchar(64)		DEFAULT ''	NOT NULL,
	oldvalue		varchar(2048)		DEFAULT ''	NOT NULL,
	newvalue		varchar(2048)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (auditdetailid)
);
CREATE INDEX auditlog_details_1 on auditlog_details (auditid);
CREATE TABLE service_alarms (
	servicealarmid		bigint		DEFAULT '0'	NOT NULL,
	serviceid		bigint		DEFAULT '0'	NOT NULL,
	clock		integer		DEFAULT '0'	NOT NULL,
	value		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (servicealarmid)
);
CREATE INDEX service_alarms_1 on service_alarms (serviceid,clock);
CREATE INDEX service_alarms_2 on service_alarms (clock);
CREATE TABLE actions (
	actionid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(255)		DEFAULT ''	NOT NULL,
	eventsource		integer		DEFAULT '0'	NOT NULL,
	evaltype		integer		DEFAULT '0'	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	esc_period		integer		DEFAULT '0'	NOT NULL,
	def_shortdata		varchar(255)		DEFAULT ''	NOT NULL,
	def_longdata		varchar(2048)		DEFAULT ''	NOT NULL,
	recovery_msg		integer		DEFAULT '0'	NOT NULL,
	r_shortdata		varchar(255)		DEFAULT ''	NOT NULL,
	r_longdata		varchar(2048)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (actionid)
);
CREATE INDEX actions_1 on actions (eventsource,status);
CREATE TABLE operations (
	operationid		bigint		DEFAULT '0'	NOT NULL,
	actionid		bigint		DEFAULT '0'	NOT NULL,
	operationtype		integer		DEFAULT '0'	NOT NULL,
	object		integer		DEFAULT '0'	NOT NULL,
	objectid		bigint		DEFAULT '0'	NOT NULL,
	shortdata		varchar(255)		DEFAULT ''	NOT NULL,
	longdata		varchar(2048)		DEFAULT ''	NOT NULL,
	esc_period		integer		DEFAULT '0'	NOT NULL,
	esc_step_from		integer		DEFAULT '0'	NOT NULL,
	esc_step_to		integer		DEFAULT '0'	NOT NULL,
	default_msg		integer		DEFAULT '0'	NOT NULL,
	evaltype		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (operationid)
);
CREATE INDEX operations_1 on operations (actionid);
CREATE TABLE opconditions (
	opconditionid		bigint		DEFAULT '0'	NOT NULL,
	operationid		bigint		DEFAULT '0'	NOT NULL,
	conditiontype		integer		DEFAULT '0'	NOT NULL,
	operator		integer		DEFAULT '0'	NOT NULL,
	value		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (opconditionid)
);
CREATE INDEX opconditions_1 on opconditions (operationid);
CREATE TABLE opmediatypes (
	opmediatypeid		bigint		DEFAULT '0'	NOT NULL,
	operationid		bigint		DEFAULT '0'	NOT NULL,
	mediatypeid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (opmediatypeid)
);
CREATE UNIQUE INDEX opmediatypes_1 on opmediatypes (operationid);
CREATE TABLE escalations (
	escalationid		bigint		DEFAULT '0'	NOT NULL,
	actionid		bigint		DEFAULT '0'	NOT NULL,
	triggerid		bigint		DEFAULT '0'	NOT NULL,
	eventid		bigint		DEFAULT '0'	NOT NULL,
	r_eventid		bigint		DEFAULT '0'	NOT NULL,
	nextcheck		integer		DEFAULT '0'	NOT NULL,
	esc_step		integer		DEFAULT '0'	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (escalationid)
);
CREATE INDEX escalations_1 on escalations (actionid,triggerid);
CREATE INDEX escalations_2 on escalations (status,nextcheck);
CREATE TABLE applications (
	applicationid		bigint		DEFAULT '0'	NOT NULL,
	hostid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(255)		DEFAULT ''	NOT NULL,
	templateid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (applicationid)
);
CREATE INDEX applications_1 on applications (templateid);
CREATE UNIQUE INDEX applications_2 on applications (hostid,name);
CREATE TABLE conditions (
	conditionid		bigint		DEFAULT '0'	NOT NULL,
	actionid		bigint		DEFAULT '0'	NOT NULL,
	conditiontype		integer		DEFAULT '0'	NOT NULL,
	operator		integer		DEFAULT '0'	NOT NULL,
	value		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (conditionid)
);
CREATE INDEX conditions_1 on conditions (actionid);
CREATE TABLE config (
	configid		bigint		DEFAULT '0'	NOT NULL,
	alert_history		integer		DEFAULT '0'	NOT NULL,
	event_history		integer		DEFAULT '0'	NOT NULL,
	refresh_unsupported		integer		DEFAULT '0'	NOT NULL,
	work_period		varchar(100)		DEFAULT '1-5,00:00-24:00'	NOT NULL,
	alert_usrgrpid		bigint		DEFAULT '0'	NOT NULL,
	event_ack_enable		integer		DEFAULT '1'	NOT NULL,
	event_expire		integer		DEFAULT '7'	NOT NULL,
	event_show_max		integer		DEFAULT '100'	NOT NULL,
	default_theme		varchar(128)		DEFAULT 'default.css'	NOT NULL,
	authentication_type		integer		DEFAULT '0'	NOT NULL,
	ldap_host		varchar(255)		DEFAULT ''	NOT NULL,
	ldap_port		integer		DEFAULT 389	NOT NULL,
	ldap_base_dn		varchar(255)		DEFAULT ''	NOT NULL,
	ldap_bind_dn		varchar(255)		DEFAULT ''	NOT NULL,
	ldap_bind_password		varchar(128)		DEFAULT ''	NOT NULL,
	ldap_search_attribute		varchar(128)		DEFAULT ''	NOT NULL,
	dropdown_first_entry		integer		DEFAULT '1'	NOT NULL,
	dropdown_first_remember		integer		DEFAULT '1'	NOT NULL,
	discovery_groupid		bigint		DEFAULT '0'	NOT NULL,
	max_in_table		integer		DEFAULT '50'	NOT NULL,
	search_limit		integer		DEFAULT '1000'	NOT NULL,
	PRIMARY KEY (configid)
);
CREATE TABLE functions (
	functionid		bigint		DEFAULT '0'	NOT NULL,
	itemid		bigint		DEFAULT '0'	NOT NULL,
	triggerid		bigint		DEFAULT '0'	NOT NULL,
	lastvalue		varchar(255)			,
	function		varchar(12)		DEFAULT ''	NOT NULL,
	parameter		varchar(255)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (functionid)
);
CREATE INDEX functions_1 on functions (triggerid);
CREATE INDEX functions_2 on functions (itemid,function,parameter);
CREATE TABLE graphs (
	graphid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(128)		DEFAULT ''	NOT NULL,
	width		integer		DEFAULT '0'	NOT NULL,
	height		integer		DEFAULT '0'	NOT NULL,
	yaxismin		decfloat(16)		DEFAULT '0'	NOT NULL,
	yaxismax		decfloat(16)		DEFAULT '0'	NOT NULL,
	templateid		bigint		DEFAULT '0'	NOT NULL,
	show_work_period		integer		DEFAULT '1'	NOT NULL,
	show_triggers		integer		DEFAULT '1'	NOT NULL,
	graphtype		integer		DEFAULT '0'	NOT NULL,
	show_legend		integer		DEFAULT '0'	NOT NULL,
	show_3d		integer		DEFAULT '0'	NOT NULL,
	percent_left		decfloat(16)		DEFAULT '0'	NOT NULL,
	percent_right		decfloat(16)		DEFAULT '0'	NOT NULL,
	ymin_type		integer		DEFAULT '0'	NOT NULL,
	ymax_type		integer		DEFAULT '0'	NOT NULL,
	ymin_itemid		bigint		DEFAULT '0'	NOT NULL,
	ymax_itemid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (graphid)
);
CREATE INDEX graphs_graphs_1 on graphs (name);
CREATE TABLE graphs_items (
	gitemid		bigint		DEFAULT '0'	NOT NULL,
	graphid		bigint		DEFAULT '0'	NOT NULL,
	itemid		bigint		DEFAULT '0'	NOT NULL,
	drawtype		integer		DEFAULT '0'	NOT NULL,
	sortorder		integer		DEFAULT '0'	NOT NULL,
	color		varchar(6)		DEFAULT '009600'	NOT NULL,
	yaxisside		integer		DEFAULT '1'	NOT NULL,
	calc_fnc		integer		DEFAULT '2'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	periods_cnt		integer		DEFAULT '5'	NOT NULL,
	PRIMARY KEY (gitemid)
);
CREATE INDEX graphs_items_1 on graphs_items (itemid);
CREATE INDEX graphs_items_2 on graphs_items (graphid);
CREATE TABLE graph_theme (
	graphthemeid		bigint		DEFAULT '0'	NOT NULL,
	description		varchar(64)		DEFAULT ''	NOT NULL,
	theme		varchar(64)		DEFAULT ''	NOT NULL,
	backgroundcolor		varchar(6)		DEFAULT 'F0F0F0'	NOT NULL,
	graphcolor		varchar(6)		DEFAULT 'FFFFFF'	NOT NULL,
	graphbordercolor		varchar(6)		DEFAULT '222222'	NOT NULL,
	gridcolor		varchar(6)		DEFAULT 'CCCCCC'	NOT NULL,
	maingridcolor		varchar(6)		DEFAULT 'AAAAAA'	NOT NULL,
	gridbordercolor		varchar(6)		DEFAULT '000000'	NOT NULL,
	textcolor		varchar(6)		DEFAULT '202020'	NOT NULL,
	highlightcolor		varchar(6)		DEFAULT 'AA4444'	NOT NULL,
	leftpercentilecolor		varchar(6)		DEFAULT '11CC11'	NOT NULL,
	rightpercentilecolor		varchar(6)		DEFAULT 'CC1111'	NOT NULL,
	noneworktimecolor		varchar(6)		DEFAULT 'CCCCCC'	NOT NULL,
	gridview		integer		DEFAULT 1	NOT NULL,
	legendview		integer		DEFAULT 1	NOT NULL,
	PRIMARY KEY (graphthemeid)
);
CREATE INDEX graph_theme_1 on graph_theme (description);
CREATE INDEX graph_theme_2 on graph_theme (theme);
CREATE TABLE groups (
	groupid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(64)		DEFAULT ''	NOT NULL,
	internal		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (groupid)
);
CREATE INDEX groups_1 on groups (name);
CREATE TABLE help_items (
	itemtype		integer		DEFAULT '0'	NOT NULL,
	key_		varchar(255)		DEFAULT ''	NOT NULL,
	description		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (itemtype,key_)
);
CREATE TABLE hosts (
	hostid		bigint		DEFAULT '0'	NOT NULL,
	proxy_hostid		bigint		DEFAULT '0'	NOT NULL,
	host		varchar(64)		DEFAULT ''	NOT NULL,
	dns		varchar(64)		DEFAULT ''	NOT NULL,
	useip		integer		DEFAULT '1'	NOT NULL,
	ip		varchar(39)		DEFAULT '127.0.0.1'	NOT NULL,
	port		integer		DEFAULT '10050'	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	disable_until		integer		DEFAULT '0'	NOT NULL,
	error		varchar(128)		DEFAULT ''	NOT NULL,
	available		integer		DEFAULT '0'	NOT NULL,
	errors_from		integer		DEFAULT '0'	NOT NULL,
	lastaccess		integer		DEFAULT '0'	NOT NULL,
	inbytes		bigint		DEFAULT '0'	NOT NULL,
	outbytes		bigint		DEFAULT '0'	NOT NULL,
	useipmi		integer		DEFAULT '0'	NOT NULL,
	ipmi_port		integer		DEFAULT '623'	NOT NULL,
	ipmi_authtype		integer		DEFAULT '0'	NOT NULL,
	ipmi_privilege		integer		DEFAULT '2'	NOT NULL,
	ipmi_username		varchar(16)		DEFAULT ''	NOT NULL,
	ipmi_password		varchar(20)		DEFAULT ''	NOT NULL,
	ipmi_disable_until		integer		DEFAULT '0'	NOT NULL,
	ipmi_available		integer		DEFAULT '0'	NOT NULL,
	snmp_disable_until		integer		DEFAULT '0'	NOT NULL,
	snmp_available		integer		DEFAULT '0'	NOT NULL,
	maintenanceid		bigint		DEFAULT '0'	NOT NULL,
	maintenance_status		integer		DEFAULT '0'	NOT NULL,
	maintenance_type		integer		DEFAULT '0'	NOT NULL,
	maintenance_from		integer		DEFAULT '0'	NOT NULL,
	ipmi_ip		varchar(64)		DEFAULT '127.0.0.1'	NOT NULL,
	ipmi_errors_from		integer		DEFAULT '0'	NOT NULL,
	snmp_errors_from		integer		DEFAULT '0'	NOT NULL,
	ipmi_error		varchar(128)		DEFAULT ''	NOT NULL,
	snmp_error		varchar(128)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (hostid)
);
CREATE INDEX hosts_1 on hosts (host);
CREATE INDEX hosts_2 on hosts (status);
CREATE INDEX hosts_3 on hosts (proxy_hostid);
CREATE TABLE globalmacro (
	globalmacroid		bigint		DEFAULT '0'	NOT NULL,
	macro		varchar(64)		DEFAULT ''	NOT NULL,
	value		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (globalmacroid)
);
CREATE INDEX globalmacro_1 on globalmacro (macro);
CREATE TABLE hostmacro (
	hostmacroid		bigint		DEFAULT '0'	NOT NULL,
	hostid		bigint		DEFAULT '0'	NOT NULL,
	macro		varchar(64)		DEFAULT ''	NOT NULL,
	value		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (hostmacroid)
);
CREATE INDEX hostmacro_1 on hostmacro (hostid,macro);
CREATE TABLE hosts_groups (
	hostgroupid		bigint		DEFAULT '0'	NOT NULL,
	hostid		bigint		DEFAULT '0'	NOT NULL,
	groupid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (hostgroupid)
);
CREATE INDEX hosts_groups_1 on hosts_groups (hostid,groupid);
CREATE INDEX hosts_groups_2 on hosts_groups (groupid);
CREATE TABLE hosts_profiles (
	hostid		bigint		DEFAULT '0'	NOT NULL,
	devicetype		varchar(64)		DEFAULT ''	NOT NULL,
	name		varchar(64)		DEFAULT ''	NOT NULL,
	os		varchar(64)		DEFAULT ''	NOT NULL,
	serialno		varchar(64)		DEFAULT ''	NOT NULL,
	tag		varchar(64)		DEFAULT ''	NOT NULL,
	macaddress		varchar(64)		DEFAULT ''	NOT NULL,
	hardware		varchar(2048)		DEFAULT ''	NOT NULL,
	software		varchar(2048)		DEFAULT ''	NOT NULL,
	contact		varchar(2048)		DEFAULT ''	NOT NULL,
	location		varchar(2048)		DEFAULT ''	NOT NULL,
	notes		varchar(2048)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (hostid)
);
CREATE TABLE hosts_profiles_ext (
	hostid		bigint		DEFAULT '0'	NOT NULL,
	device_alias		varchar(64)		DEFAULT ''	NOT NULL,
	device_type		varchar(64)		DEFAULT ''	NOT NULL,
	device_chassis		varchar(64)		DEFAULT ''	NOT NULL,
	device_os		varchar(64)		DEFAULT ''	NOT NULL,
	device_os_short		varchar(64)		DEFAULT ''	NOT NULL,
	device_hw_arch		varchar(32)		DEFAULT ''	NOT NULL,
	device_serial		varchar(64)		DEFAULT ''	NOT NULL,
	device_model		varchar(64)		DEFAULT ''	NOT NULL,
	device_tag		varchar(64)		DEFAULT ''	NOT NULL,
	device_vendor		varchar(64)		DEFAULT ''	NOT NULL,
	device_contract		varchar(64)		DEFAULT ''	NOT NULL,
	device_who		varchar(64)		DEFAULT ''	NOT NULL,
	device_status		varchar(64)		DEFAULT ''	NOT NULL,
	device_app_01		varchar(64)		DEFAULT ''	NOT NULL,
	device_app_02		varchar(64)		DEFAULT ''	NOT NULL,
	device_app_03		varchar(64)		DEFAULT ''	NOT NULL,
	device_app_04		varchar(64)		DEFAULT ''	NOT NULL,
	device_app_05		varchar(64)		DEFAULT ''	NOT NULL,
	device_url_1		varchar(255)		DEFAULT ''	NOT NULL,
	device_url_2		varchar(255)		DEFAULT ''	NOT NULL,
	device_url_3		varchar(255)		DEFAULT ''	NOT NULL,
	device_networks		varchar(2048)		DEFAULT ''	NOT NULL,
	device_notes		varchar(2048)		DEFAULT ''	NOT NULL,
	device_hardware		varchar(2048)		DEFAULT ''	NOT NULL,
	device_software		varchar(2048)		DEFAULT ''	NOT NULL,
	ip_subnet_mask		varchar(39)		DEFAULT ''	NOT NULL,
	ip_router		varchar(39)		DEFAULT ''	NOT NULL,
	ip_macaddress		varchar(64)		DEFAULT ''	NOT NULL,
	oob_ip		varchar(39)		DEFAULT ''	NOT NULL,
	oob_subnet_mask		varchar(39)		DEFAULT ''	NOT NULL,
	oob_router		varchar(39)		DEFAULT ''	NOT NULL,
	date_hw_buy		varchar(64)		DEFAULT ''	NOT NULL,
	date_hw_install		varchar(64)		DEFAULT ''	NOT NULL,
	date_hw_expiry		varchar(64)		DEFAULT ''	NOT NULL,
	date_hw_decomm		varchar(64)		DEFAULT ''	NOT NULL,
	site_street_1		varchar(128)		DEFAULT ''	NOT NULL,
	site_street_2		varchar(128)		DEFAULT ''	NOT NULL,
	site_street_3		varchar(128)		DEFAULT ''	NOT NULL,
	site_city		varchar(128)		DEFAULT ''	NOT NULL,
	site_state		varchar(64)		DEFAULT ''	NOT NULL,
	site_country		varchar(64)		DEFAULT ''	NOT NULL,
	site_zip		varchar(64)		DEFAULT ''	NOT NULL,
	site_rack		varchar(128)		DEFAULT ''	NOT NULL,
	site_notes		varchar(2048)		DEFAULT ''	NOT NULL,
	poc_1_name		varchar(128)		DEFAULT ''	NOT NULL,
	poc_1_email		varchar(128)		DEFAULT ''	NOT NULL,
	poc_1_phone_1		varchar(64)		DEFAULT ''	NOT NULL,
	poc_1_phone_2		varchar(64)		DEFAULT ''	NOT NULL,
	poc_1_cell		varchar(64)		DEFAULT ''	NOT NULL,
	poc_1_screen		varchar(64)		DEFAULT ''	NOT NULL,
	poc_1_notes		varchar(2048)		DEFAULT ''	NOT NULL,
	poc_2_name		varchar(128)		DEFAULT ''	NOT NULL,
	poc_2_email		varchar(128)		DEFAULT ''	NOT NULL,
	poc_2_phone_1		varchar(64)		DEFAULT ''	NOT NULL,
	poc_2_phone_2		varchar(64)		DEFAULT ''	NOT NULL,
	poc_2_cell		varchar(64)		DEFAULT ''	NOT NULL,
	poc_2_screen		varchar(64)		DEFAULT ''	NOT NULL,
	poc_2_notes		varchar(2048)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (hostid)
);
CREATE TABLE hosts_templates (
	hosttemplateid		bigint		DEFAULT '0'	NOT NULL,
	hostid		bigint		DEFAULT '0'	NOT NULL,
	templateid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (hosttemplateid)
);
CREATE UNIQUE INDEX hosts_templates_1 on hosts_templates (hostid,templateid);
CREATE INDEX hosts_templates_2 on hosts_templates (templateid);
CREATE TABLE housekeeper (
	housekeeperid		bigint		DEFAULT '0'	NOT NULL,
	tablename		varchar(64)		DEFAULT ''	NOT NULL,
	field		varchar(64)		DEFAULT ''	NOT NULL,
	value		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (housekeeperid)
);
CREATE TABLE images (
	imageid		bigint		DEFAULT '0'	NOT NULL,
	imagetype		integer		DEFAULT '0'	NOT NULL,
	name		varchar(64)		DEFAULT '0'	NOT NULL,
	image		blob			NOT NULL,
	PRIMARY KEY (imageid)
);
CREATE INDEX images_1 on images (imagetype,name);
CREATE TABLE items (
	itemid		bigint		DEFAULT '0'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	snmp_community		varchar(64)		DEFAULT ''	NOT NULL,
	snmp_oid		varchar(255)		DEFAULT ''	NOT NULL,
	snmp_port		integer		DEFAULT '161'	NOT NULL,
	hostid		bigint		DEFAULT '0'	NOT NULL,
	description		varchar(255)		DEFAULT ''	NOT NULL,
	key_		varchar(255)		DEFAULT ''	NOT NULL,
	delay		integer		DEFAULT '0'	NOT NULL,
	history		integer		DEFAULT '90'	NOT NULL,
	trends		integer		DEFAULT '365'	NOT NULL,
	lastvalue		varchar(255)			NULL,
	lastclock		integer			NULL,
	prevvalue		varchar(255)			NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	value_type		integer		DEFAULT '0'	NOT NULL,
	trapper_hosts		varchar(255)		DEFAULT ''	NOT NULL,
	units		varchar(10)		DEFAULT ''	NOT NULL,
	multiplier		integer		DEFAULT '0'	NOT NULL,
	delta		integer		DEFAULT '0'	NOT NULL,
	prevorgvalue		varchar(255)			NULL,
	snmpv3_securityname		varchar(64)		DEFAULT ''	NOT NULL,
	snmpv3_securitylevel		integer		DEFAULT '0'	NOT NULL,
	snmpv3_authpassphrase		varchar(64)		DEFAULT ''	NOT NULL,
	snmpv3_privpassphrase		varchar(64)		DEFAULT ''	NOT NULL,
	formula		varchar(255)		DEFAULT '1'	NOT NULL,
	error		varchar(128)		DEFAULT ''	NOT NULL,
	lastlogsize		integer		DEFAULT '0'	NOT NULL,
	logtimefmt		varchar(64)		DEFAULT ''	NOT NULL,
	templateid		bigint		DEFAULT '0'	NOT NULL,
	valuemapid		bigint		DEFAULT '0'	NOT NULL,
	delay_flex		varchar(255)		DEFAULT ''	NOT NULL,
	params		varchar(2048)		DEFAULT ''	NOT NULL,
	ipmi_sensor		varchar(128)		DEFAULT ''	NOT NULL,
	data_type		integer		DEFAULT '0'	NOT NULL,
	authtype		integer		DEFAULT '0'	NOT NULL,
	username		varchar(64)		DEFAULT ''	NOT NULL,
	password		varchar(64)		DEFAULT ''	NOT NULL,
	publickey		varchar(64)		DEFAULT ''	NOT NULL,
	privatekey		varchar(64)		DEFAULT ''	NOT NULL,
	mtime		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (itemid)
);
CREATE UNIQUE INDEX items_1 on items (hostid,key_);
CREATE INDEX items_3 on items (status);
CREATE INDEX items_4 on items (templateid);
CREATE TABLE items_applications (
	itemappid		bigint		DEFAULT '0'	NOT NULL,
	applicationid		bigint		DEFAULT '0'	NOT NULL,
	itemid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (itemappid)
);
CREATE INDEX items_applications_1 on items_applications (applicationid,itemid);
CREATE INDEX items_applications_2 on items_applications (itemid);
CREATE TABLE mappings (
	mappingid		bigint		DEFAULT '0'	NOT NULL,
	valuemapid		bigint		DEFAULT '0'	NOT NULL,
	value		varchar(64)		DEFAULT ''	NOT NULL,
	newvalue		varchar(64)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (mappingid)
);
CREATE INDEX mappings_1 on mappings (valuemapid);
CREATE TABLE media (
	mediaid		bigint		DEFAULT '0'	NOT NULL,
	userid		bigint		DEFAULT '0'	NOT NULL,
	mediatypeid		bigint		DEFAULT '0'	NOT NULL,
	sendto		varchar(100)		DEFAULT ''	NOT NULL,
	active		integer		DEFAULT '0'	NOT NULL,
	severity		integer		DEFAULT '63'	NOT NULL,
	period		varchar(100)		DEFAULT '1-7,00:00-23:59'	NOT NULL,
	PRIMARY KEY (mediaid)
);
CREATE INDEX media_1 on media (userid);
CREATE INDEX media_2 on media (mediatypeid);
CREATE TABLE media_type (
	mediatypeid		bigint		DEFAULT '0'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	description		varchar(100)		DEFAULT ''	NOT NULL,
	smtp_server		varchar(255)		DEFAULT ''	NOT NULL,
	smtp_helo		varchar(255)		DEFAULT ''	NOT NULL,
	smtp_email		varchar(255)		DEFAULT ''	NOT NULL,
	exec_path		varchar(255)		DEFAULT ''	NOT NULL,
	gsm_modem		varchar(255)		DEFAULT ''	NOT NULL,
	username		varchar(255)		DEFAULT ''	NOT NULL,
	passwd		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (mediatypeid)
);
CREATE TABLE profiles (
	profileid		bigint		DEFAULT '0'	NOT NULL,
	userid		bigint		DEFAULT '0'	NOT NULL,
	idx		varchar(96)		DEFAULT ''	NOT NULL,
	idx2		bigint		DEFAULT '0'	NOT NULL,
	value_id		bigint		DEFAULT '0'	NOT NULL,
	value_int		integer		DEFAULT '0'	NOT NULL,
	value_str		varchar(255)		DEFAULT ''	NOT NULL,
	source		varchar(96)		DEFAULT ''	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (profileid)
);
CREATE INDEX profiles_1 on profiles (userid,idx,idx2);
CREATE INDEX profiles_2 on profiles (userid,profileid);
CREATE TABLE rights (
	rightid		bigint		DEFAULT '0'	NOT NULL,
	groupid		bigint		DEFAULT '0'	NOT NULL,
	permission		integer		DEFAULT '0'	NOT NULL,
	id		bigint			,
	PRIMARY KEY (rightid)
);
CREATE INDEX rights_1 on rights (groupid);
CREATE INDEX rights_2 on rights (id);
CREATE TABLE scripts (
	scriptid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(255)		DEFAULT ''	NOT NULL,
	command		varchar(255)		DEFAULT ''	NOT NULL,
	host_access		integer		DEFAULT '2'	NOT NULL,
	usrgrpid		bigint		DEFAULT '0'	NOT NULL,
	groupid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (scriptid)
);
CREATE TABLE screens (
	screenid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(255)		DEFAULT 'Screen'	NOT NULL,
	hsize		integer		DEFAULT '1'	NOT NULL,
	vsize		integer		DEFAULT '1'	NOT NULL,
	PRIMARY KEY (screenid)
);
CREATE TABLE screens_items (
	screenitemid		bigint		DEFAULT '0'	NOT NULL,
	screenid		bigint		DEFAULT '0'	NOT NULL,
	resourcetype		integer		DEFAULT '0'	NOT NULL,
	resourceid		bigint		DEFAULT '0'	NOT NULL,
	width		integer		DEFAULT '320'	NOT NULL,
	height		integer		DEFAULT '200'	NOT NULL,
	x		integer		DEFAULT '0'	NOT NULL,
	y		integer		DEFAULT '0'	NOT NULL,
	colspan		integer		DEFAULT '0'	NOT NULL,
	rowspan		integer		DEFAULT '0'	NOT NULL,
	elements		integer		DEFAULT '25'	NOT NULL,
	valign		integer		DEFAULT '0'	NOT NULL,
	halign		integer		DEFAULT '0'	NOT NULL,
	style		integer		DEFAULT '0'	NOT NULL,
	url		varchar(255)		DEFAULT ''	NOT NULL,
	dynamic		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (screenitemid)
);
CREATE TABLE services (
	serviceid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(128)		DEFAULT ''	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	algorithm		integer		DEFAULT '0'	NOT NULL,
	triggerid		bigint			,
	showsla		integer		DEFAULT '0'	NOT NULL,
	goodsla		decfloat(16)		DEFAULT '99.9'	NOT NULL,
	sortorder		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (serviceid)
);
CREATE INDEX services_1 on services (triggerid);
CREATE TABLE services_links (
	linkid		bigint		DEFAULT '0'	NOT NULL,
	serviceupid		bigint		DEFAULT '0'	NOT NULL,
	servicedownid		bigint		DEFAULT '0'	NOT NULL,
	soft		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (linkid)
);
CREATE INDEX services_links_links_1 on services_links (servicedownid);
CREATE UNIQUE INDEX services_links_links_2 on services_links (serviceupid,servicedownid);
CREATE TABLE sessions (
	sessionid		varchar(32)		DEFAULT ''	NOT NULL,
	userid		bigint		DEFAULT '0'	NOT NULL,
	lastaccess		integer		DEFAULT '0'	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (sessionid)
);
CREATE INDEX sessions_1 on sessions (userid, status);
CREATE TABLE sysmaps_links (
	linkid		bigint		DEFAULT '0'	NOT NULL,
	sysmapid		bigint		DEFAULT '0'	NOT NULL,
	selementid1		bigint		DEFAULT '0'	NOT NULL,
	selementid2		bigint		DEFAULT '0'	NOT NULL,
	drawtype		integer		DEFAULT '0'	NOT NULL,
	color		varchar(6)		DEFAULT '000000'	NOT NULL,
	label		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (linkid)
);
CREATE TABLE sysmaps_link_triggers (
	linktriggerid		bigint		DEFAULT '0'	NOT NULL,
	linkid		bigint		DEFAULT '0'	NOT NULL,
	triggerid		bigint		DEFAULT '0'	NOT NULL,
	drawtype		integer		DEFAULT '0'	NOT NULL,
	color		varchar(6)		DEFAULT '000000'	NOT NULL,
	PRIMARY KEY (linktriggerid)
);
CREATE UNIQUE INDEX sysmaps_link_triggers_1 on sysmaps_link_triggers (linkid,triggerid);
CREATE TABLE sysmaps_elements (
	selementid		bigint		DEFAULT '0'	NOT NULL,
	sysmapid		bigint		DEFAULT '0'	NOT NULL,
	elementid		bigint		DEFAULT '0'	NOT NULL,
	elementtype		integer		DEFAULT '0'	NOT NULL,
	iconid_off		bigint		DEFAULT '0'	NOT NULL,
	iconid_on		bigint		DEFAULT '0'	NOT NULL,
	iconid_unknown		bigint		DEFAULT '0'	NOT NULL,
	label		varchar(255)		DEFAULT ''	NOT NULL,
	label_location		integer			NULL,
	x		integer		DEFAULT '0'	NOT NULL,
	y		integer		DEFAULT '0'	NOT NULL,
	url		varchar(255)		DEFAULT ''	NOT NULL,
	iconid_disabled		bigint		DEFAULT '0'	NOT NULL,
	iconid_maintenance		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (selementid)
);
CREATE TABLE sysmaps (
	sysmapid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(128)		DEFAULT ''	NOT NULL,
	width		integer		DEFAULT '0'	NOT NULL,
	height		integer		DEFAULT '0'	NOT NULL,
	backgroundid		bigint		DEFAULT '0'	NOT NULL,
	label_type		integer		DEFAULT '0'	NOT NULL,
	label_location		integer		DEFAULT '0'	NOT NULL,
	highlight		integer		DEFAULT '1'	NOT NULL,
	PRIMARY KEY (sysmapid)
);
CREATE INDEX sysmaps_1 on sysmaps (name);
CREATE TABLE triggers (
	triggerid		bigint		DEFAULT '0'	NOT NULL,
	expression		varchar(255)		DEFAULT ''	NOT NULL,
	description		varchar(255)		DEFAULT ''	NOT NULL,
	url		varchar(255)		DEFAULT ''	NOT NULL,
	status		integer		DEFAULT '0'	NOT NULL,
	value		integer		DEFAULT '0'	NOT NULL,
	priority		integer		DEFAULT '0'	NOT NULL,
	lastchange		integer		DEFAULT '0'	NOT NULL,
	dep_level		integer		DEFAULT '0'	NOT NULL,
	comments		varchar(2048)		DEFAULT ''	NOT NULL,
	error		varchar(128)		DEFAULT ''	NOT NULL,
	templateid		bigint		DEFAULT '0'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (triggerid)
);
CREATE INDEX triggers_1 on triggers (status);
CREATE INDEX triggers_2 on triggers (value);
CREATE TABLE trigger_depends (
	triggerdepid		bigint		DEFAULT '0'	NOT NULL,
	triggerid_down		bigint		DEFAULT '0'	NOT NULL,
	triggerid_up		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (triggerdepid)
);
CREATE INDEX trigger_depends_1 on trigger_depends (triggerid_down,triggerid_up);
CREATE INDEX trigger_depends_2 on trigger_depends (triggerid_up);
CREATE TABLE users (
	userid		bigint		DEFAULT '0'	NOT NULL,
	alias		varchar(100)		DEFAULT ''	NOT NULL,
	name		varchar(100)		DEFAULT ''	NOT NULL,
	surname		varchar(100)		DEFAULT ''	NOT NULL,
	passwd		varchar(32)		DEFAULT ''	NOT NULL,
	url		varchar(255)		DEFAULT ''	NOT NULL,
	autologin		integer		DEFAULT '0'	NOT NULL,
	autologout		integer		DEFAULT '900'	NOT NULL,
	lang		varchar(5)		DEFAULT 'en_gb'	NOT NULL,
	refresh		integer		DEFAULT '30'	NOT NULL,
	type		integer		DEFAULT '0'	NOT NULL,
	theme		varchar(128)		DEFAULT 'default.css'	NOT NULL,
	attempt_failed		integer		DEFAULT 0	NOT NULL,
	attempt_ip		varchar(39)		DEFAULT ''	NOT NULL,
	attempt_clock		integer		DEFAULT 0	NOT NULL,
	rows_per_page		integer		DEFAULT 50	NOT NULL,
	PRIMARY KEY (userid)
);
CREATE INDEX users_1 on users (alias);
CREATE TABLE usrgrp (
	usrgrpid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(64)		DEFAULT ''	NOT NULL,
	gui_access		integer		DEFAULT '0'	NOT NULL,
	users_status		integer		DEFAULT '0'	NOT NULL,
	api_access		integer		DEFAULT '0'	NOT NULL,
	debug_mode		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (usrgrpid)
);
CREATE INDEX usrgrp_1 on usrgrp (name);
CREATE TABLE users_groups (
	id		bigint		DEFAULT '0'	NOT NULL,
	usrgrpid		bigint		DEFAULT '0'	NOT NULL,
	userid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (id)
);
CREATE INDEX users_groups_1 on users_groups (usrgrpid,userid);
CREATE TABLE valuemaps (
	valuemapid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(64)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (valuemapid)
);
CREATE INDEX valuemaps_1 on valuemaps (name);
CREATE TABLE maintenances (
	maintenanceid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(128)		DEFAULT ''	NOT NULL,
	maintenance_type		integer		DEFAULT '0'	NOT NULL,
	description		varchar(2048)		DEFAULT ''	NOT NULL,
	active_since		integer		DEFAULT '0'	NOT NULL,
	active_till		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (maintenanceid)
);
CREATE INDEX maintenances_1 on maintenances (active_since,active_till);
CREATE TABLE maintenances_hosts (
	maintenance_hostid		bigint		DEFAULT '0'	NOT NULL,
	maintenanceid		bigint		DEFAULT '0'	NOT NULL,
	hostid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (maintenance_hostid)
);
CREATE INDEX maintenances_hosts_1 on maintenances_hosts (maintenanceid,hostid);
CREATE TABLE maintenances_groups (
	maintenance_groupid		bigint		DEFAULT '0'	NOT NULL,
	maintenanceid		bigint		DEFAULT '0'	NOT NULL,
	groupid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (maintenance_groupid)
);
CREATE INDEX maintenances_groups_1 on maintenances_groups (maintenanceid,groupid);
CREATE TABLE maintenances_windows (
	maintenance_timeperiodid		bigint		DEFAULT '0'	NOT NULL,
	maintenanceid		bigint		DEFAULT '0'	NOT NULL,
	timeperiodid		bigint		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (maintenance_timeperiodid)
);
CREATE INDEX maintenances_windows_1 on maintenances_windows (maintenanceid,timeperiodid);
CREATE TABLE timeperiods (
	timeperiodid		bigint		DEFAULT '0'	NOT NULL,
	timeperiod_type		integer		DEFAULT '0'	NOT NULL,
	every		integer		DEFAULT '0'	NOT NULL,
	month		integer		DEFAULT '0'	NOT NULL,
	dayofweek		integer		DEFAULT '0'	NOT NULL,
	day		integer		DEFAULT '0'	NOT NULL,
	start_time		integer		DEFAULT '0'	NOT NULL,
	period		integer		DEFAULT '0'	NOT NULL,
	start_date		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (timeperiodid)
);
CREATE TABLE regexps (
	regexpid		bigint		DEFAULT '0'	NOT NULL,
	name		varchar(128)		DEFAULT ''	NOT NULL,
	test_string		varchar(2048)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (regexpid)
);
CREATE INDEX regexps_1 on regexps (name);
CREATE TABLE user_history (
	userhistoryid		bigint		DEFAULT '0'	NOT NULL,
	userid		bigint		DEFAULT '0'	NOT NULL,
	title1		varchar(255)		DEFAULT ''	NOT NULL,
	url1		varchar(255)		DEFAULT ''	NOT NULL,
	title2		varchar(255)		DEFAULT ''	NOT NULL,
	url2		varchar(255)		DEFAULT ''	NOT NULL,
	title3		varchar(255)		DEFAULT ''	NOT NULL,
	url3		varchar(255)		DEFAULT ''	NOT NULL,
	title4		varchar(255)		DEFAULT ''	NOT NULL,
	url4		varchar(255)		DEFAULT ''	NOT NULL,
	title5		varchar(255)		DEFAULT ''	NOT NULL,
	url5		varchar(255)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (userhistoryid)
);
CREATE UNIQUE INDEX user_history_1 on user_history (userid);
CREATE TABLE expressions (
	expressionid		bigint		DEFAULT '0'	NOT NULL,
	regexpid		bigint		DEFAULT '0'	NOT NULL,
	expression		varchar(255)		DEFAULT ''	NOT NULL,
	expression_type		integer		DEFAULT '0'	NOT NULL,
	exp_delimiter		varchar(1)		DEFAULT ''	NOT NULL,
	case_sensitive		integer		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (expressionid)
);
CREATE INDEX expressions_1 on expressions (regexpid);
CREATE TABLE autoreg_host (
	autoreg_hostid		bigint		DEFAULT '0'	NOT NULL,
	proxy_hostid		bigint		DEFAULT '0'	NOT NULL,
	host		varchar(64)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (autoreg_hostid)
);
CREATE INDEX autoreg_host_1 on autoreg_host (proxy_hostid,host);
CREATE TABLE proxy_autoreg_host (
	id		bigint			NOT NULL	GENERATED ALWAYS AS IDENTITY (START WITH 1 INCREMENT BY 1),
	clock		integer		DEFAULT '0'	NOT NULL,
	host		varchar(64)		DEFAULT ''	NOT NULL,
	PRIMARY KEY (id)
);
CREATE INDEX proxy_autoreg_host_1 on proxy_autoreg_host (clock);
