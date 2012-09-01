CREATE TABLE slideshows (
	slideshowid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(255)		DEFAULT '',
	delay		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (slideshowid)
)
/

CREATE TABLE slides (
	slideid		number(20)		DEFAULT '0'	NOT NULL,
	slideshowid		number(20)		DEFAULT '0'	NOT NULL,
	screenid		number(20)		DEFAULT '0'	NOT NULL,
	step		number(10)		DEFAULT '0'	NOT NULL,
	delay		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (slideid)
)
/

CREATE INDEX slides_slides_1 on slides (slideshowid)
/

CREATE TABLE drules (
	druleid		number(20)		DEFAULT '0'	NOT NULL,
	proxy_hostid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(255)		DEFAULT '',
	iprange		nvarchar2(255)		DEFAULT '',
	delay		number(10)		DEFAULT '0'	NOT NULL,
	nextcheck		number(10)		DEFAULT '0'	NOT NULL,
	status		number(10)		DEFAULT '0'	NOT NULL,
	unique_dcheckid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (druleid)
)
/

CREATE TABLE dchecks (
	dcheckid		number(20)		DEFAULT '0'	NOT NULL,
	druleid		number(20)		DEFAULT '0'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	key_		nvarchar2(255)		DEFAULT '0',
	snmp_community		nvarchar2(255)		DEFAULT '0',
	ports		nvarchar2(255)		DEFAULT '0',
	snmpv3_securityname		nvarchar2(64)		DEFAULT '',
	snmpv3_securitylevel		number(10)		DEFAULT '0'	NOT NULL,
	snmpv3_authpassphrase		nvarchar2(64)		DEFAULT '',
	snmpv3_privpassphrase		nvarchar2(64)		DEFAULT '',
	PRIMARY KEY (dcheckid)
)
/

CREATE INDEX dchecks_1 on dchecks (druleid)
/

CREATE TABLE dhosts (
	dhostid		number(20)		DEFAULT '0'	NOT NULL,
	druleid		number(20)		DEFAULT '0'	NOT NULL,
	status		number(10)		DEFAULT '0'	NOT NULL,
	lastup		number(10)		DEFAULT '0'	NOT NULL,
	lastdown		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (dhostid)
)
/

CREATE INDEX dhosts_1 on dhosts (druleid)
/

CREATE TABLE dservices (
	dserviceid		number(20)		DEFAULT '0'	NOT NULL,
	dhostid		number(20)		DEFAULT '0'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	key_		nvarchar2(255)		DEFAULT '0',
	value		nvarchar2(255)		DEFAULT '0',
	port		number(10)		DEFAULT '0'	NOT NULL,
	status		number(10)		DEFAULT '0'	NOT NULL,
	lastup		number(10)		DEFAULT '0'	NOT NULL,
	lastdown		number(10)		DEFAULT '0'	NOT NULL,
	dcheckid		number(20)		DEFAULT '0'	NOT NULL,
	ip		nvarchar2(39)		DEFAULT '',
	PRIMARY KEY (dserviceid)
)
/

CREATE UNIQUE INDEX dservices_1 on dservices (dcheckid,type,key_,ip,port)
/

CREATE INDEX dservices_2 on dservices (dhostid)
/

CREATE TABLE ids (
	nodeid		number(10)		DEFAULT '0'	NOT NULL,
	table_name		nvarchar2(64)		DEFAULT '',
	field_name		nvarchar2(64)		DEFAULT '',
	nextid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (nodeid,table_name,field_name)
)
/

CREATE TABLE httptest (
	httptestid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(64)		DEFAULT '',
	applicationid		number(20)		DEFAULT '0'	NOT NULL,
	lastcheck		number(10)		DEFAULT '0'	NOT NULL,
	nextcheck		number(10)		DEFAULT '0'	NOT NULL,
	curstate		number(10)		DEFAULT '0'	NOT NULL,
	curstep		number(10)		DEFAULT '0'	NOT NULL,
	lastfailedstep		number(10)		DEFAULT '0'	NOT NULL,
	delay		number(10)		DEFAULT '60'	NOT NULL,
	status		number(10)		DEFAULT '0'	NOT NULL,
	macros		nvarchar2(2048)		DEFAULT '',
	agent		nvarchar2(255)		DEFAULT '',
	time		number(20,4)		DEFAULT '0'	NOT NULL,
	error		nvarchar2(255)		DEFAULT '',
	authentication		number(10)		DEFAULT '0'	NOT NULL,
	http_user		nvarchar2(64)		DEFAULT '',
	http_password		nvarchar2(64)		DEFAULT '',
	PRIMARY KEY (httptestid)
)
/

CREATE INDEX httptest_httptest_1 on httptest (applicationid)
/

CREATE INDEX httptest_2 on httptest (name)
/

CREATE INDEX httptest_3 on httptest (status)
/

CREATE TABLE httpstep (
	httpstepid		number(20)		DEFAULT '0'	NOT NULL,
	httptestid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(64)		DEFAULT '',
	no		number(10)		DEFAULT '0'	NOT NULL,
	url		nvarchar2(255)		DEFAULT '',
	timeout		number(10)		DEFAULT '30'	NOT NULL,
	posts		nvarchar2(2048)		DEFAULT '',
	required		nvarchar2(255)		DEFAULT '',
	status_codes		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (httpstepid)
)
/

CREATE INDEX httpstep_httpstep_1 on httpstep (httptestid)
/

CREATE TABLE httpstepitem (
	httpstepitemid		number(20)		DEFAULT '0'	NOT NULL,
	httpstepid		number(20)		DEFAULT '0'	NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (httpstepitemid)
)
/

CREATE UNIQUE INDEX httpstepitem_httpstepitem_1 on httpstepitem (httpstepid,itemid)
/

CREATE TABLE httptestitem (
	httptestitemid		number(20)		DEFAULT '0'	NOT NULL,
	httptestid		number(20)		DEFAULT '0'	NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (httptestitemid)
)
/

CREATE UNIQUE INDEX httptestitem_httptestitem_1 on httptestitem (httptestid,itemid)
/

CREATE TABLE nodes (
	nodeid		number(10)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(64)		DEFAULT '0',
	timezone		number(10)		DEFAULT '0'	NOT NULL,
	ip		nvarchar2(39)		DEFAULT '',
	port		number(10)		DEFAULT '10051'	NOT NULL,
	slave_history		number(10)		DEFAULT '30'	NOT NULL,
	slave_trends		number(10)		DEFAULT '365'	NOT NULL,
	nodetype		number(10)		DEFAULT '0'	NOT NULL,
	masterid		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (nodeid)
)
/

CREATE TABLE node_cksum (
	nodeid		number(10)		DEFAULT '0'	NOT NULL,
	tablename		nvarchar2(64)		DEFAULT '',
	recordid		number(20)		DEFAULT '0'	NOT NULL,
	cksumtype		number(10)		DEFAULT '0'	NOT NULL,
	cksum		nclob		DEFAULT '',
	sync		nvarchar2(128)		DEFAULT ''
)
/

CREATE INDEX node_cksum_1 on node_cksum (nodeid,cksumtype,tablename,recordid)
/

CREATE TABLE services_times (
	timeid		number(20)		DEFAULT '0'	NOT NULL,
	serviceid		number(20)		DEFAULT '0'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	ts_from		number(10)		DEFAULT '0'	NOT NULL,
	ts_to		number(10)		DEFAULT '0'	NOT NULL,
	note		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (timeid)
)
/

CREATE INDEX services_times_times_1 on services_times (serviceid,type,ts_from,ts_to)
/

CREATE TABLE alerts (
	alertid		number(20)		DEFAULT '0'	NOT NULL,
	actionid		number(20)		DEFAULT '0'	NOT NULL,
	eventid		number(20)		DEFAULT '0'	NOT NULL,
	userid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	mediatypeid		number(20)		DEFAULT '0'	NOT NULL,
	sendto		nvarchar2(100)		DEFAULT '',
	subject		nvarchar2(255)		DEFAULT '',
	message		nvarchar2(2048)		DEFAULT '',
	status		number(10)		DEFAULT '0'	NOT NULL,
	retries		number(10)		DEFAULT '0'	NOT NULL,
	error		nvarchar2(128)		DEFAULT '',
	nextcheck		number(10)		DEFAULT '0'	NOT NULL,
	esc_step		number(10)		DEFAULT '0'	NOT NULL,
	alerttype		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (alertid)
)
/

CREATE INDEX alerts_1 on alerts (actionid)
/

CREATE INDEX alerts_2 on alerts (clock)
/

CREATE INDEX alerts_3 on alerts (eventid)
/

CREATE INDEX alerts_4 on alerts (status,retries)
/

CREATE INDEX alerts_5 on alerts (mediatypeid)
/

CREATE INDEX alerts_6 on alerts (userid)
/

CREATE TABLE history (
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	value		number(20,4)		DEFAULT '0.0000'	NOT NULL
)
/

CREATE INDEX history_1 on history (itemid,clock)
/

CREATE TABLE history_sync (
	id		number(20)			NOT NULL,
	nodeid		number(20)		DEFAULT '0'	NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	value		number(20,4)		DEFAULT '0.0000'	NOT NULL,
	PRIMARY KEY (id)
)
/

CREATE INDEX history_sync_1 on history_sync (nodeid,id)
/

CREATE SEQUENCE history_sync_seq
START WITH 1
INCREMENT BY 1
NOMAXVALUE
/

CREATE TRIGGER history_sync_tr
BEFORE INSERT ON history_sync
FOR EACH ROW
BEGIN
SELECT proxy_history_seq.nextval INTO :new.id FROM dual;
END;
/

CREATE TABLE history_uint (
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	value		number(20)		DEFAULT '0'	NOT NULL
)
/

CREATE INDEX history_uint_1 on history_uint (itemid,clock)
/

CREATE TABLE history_uint_sync (
	id		number(20)			NOT NULL,
	nodeid		number(20)		DEFAULT '0'	NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	value		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (id)
)
/

CREATE INDEX history_uint_sync_1 on history_uint_sync (nodeid,id)
/

CREATE SEQUENCE history_uint_sync_seq
START WITH 1
INCREMENT BY 1
NOMAXVALUE
/

CREATE TRIGGER history_uint_sync_tr
BEFORE INSERT ON history_uint_sync
FOR EACH ROW
BEGIN
SELECT proxy_history_seq.nextval INTO :new.id FROM dual;
END;
/

CREATE TABLE history_str (
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	value		nvarchar2(255)		DEFAULT ''
)
/

CREATE INDEX history_str_1 on history_str (itemid,clock)
/

CREATE TABLE history_str_sync (
	id		number(20)			NOT NULL,
	nodeid		number(20)		DEFAULT '0'	NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	value		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (id)
)
/

CREATE INDEX history_str_sync_1 on history_str_sync (nodeid,id)
/

CREATE SEQUENCE history_str_sync_seq
START WITH 1
INCREMENT BY 1
NOMAXVALUE
/

CREATE TRIGGER history_str_sync_tr
BEFORE INSERT ON history_str_sync
FOR EACH ROW
BEGIN
SELECT proxy_history_seq.nextval INTO :new.id FROM dual;
END;
/

CREATE TABLE history_log (
	id		number(20)		DEFAULT '0'	NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	timestamp		number(10)		DEFAULT '0'	NOT NULL,
	source		nvarchar2(64)		DEFAULT '',
	severity		number(10)		DEFAULT '0'	NOT NULL,
	value		nclob		DEFAULT '',
	logeventid		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (id)
)
/

CREATE INDEX history_log_1 on history_log (itemid,clock)
/

CREATE UNIQUE INDEX history_log_2 on history_log (itemid,id)
/

CREATE TABLE history_text (
	id		number(20)		DEFAULT '0'	NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	value		nclob		DEFAULT '',
	PRIMARY KEY (id)
)
/

CREATE INDEX history_text_1 on history_text (itemid,clock)
/

CREATE UNIQUE INDEX history_text_2 on history_text (itemid,id)
/

CREATE TABLE proxy_history (
	id		number(20)			NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	timestamp		number(10)		DEFAULT '0'	NOT NULL,
	source		nvarchar2(64)		DEFAULT '',
	severity		number(10)		DEFAULT '0'	NOT NULL,
	value		nclob		DEFAULT '',
	logeventid		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (id)
)
/

CREATE INDEX proxy_history_1 on proxy_history (clock)
/

CREATE SEQUENCE proxy_history_seq
START WITH 1
INCREMENT BY 1
NOMAXVALUE
/

CREATE TRIGGER proxy_history_tr
BEFORE INSERT ON proxy_history
FOR EACH ROW
BEGIN
SELECT proxy_history_seq.nextval INTO :new.id FROM dual;
END;
/

CREATE TABLE proxy_dhistory (
	id		number(20)			NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	druleid		number(20)		DEFAULT '0'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	ip		nvarchar2(39)		DEFAULT '',
	port		number(10)		DEFAULT '0'	NOT NULL,
	key_		nvarchar2(255)		DEFAULT '',
	value		nvarchar2(255)		DEFAULT '',
	status		number(10)		DEFAULT '0'	NOT NULL,
	dcheckid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (id)
)
/

CREATE INDEX proxy_dhistory_1 on proxy_dhistory (clock)
/

CREATE SEQUENCE proxy_dhistory_seq
START WITH 1
INCREMENT BY 1
NOMAXVALUE
/

CREATE TRIGGER proxy_dhistory_tr
BEFORE INSERT ON proxy_dhistory
FOR EACH ROW
BEGIN
SELECT proxy_history_seq.nextval INTO :new.id FROM dual;
END;
/

CREATE TABLE events (
	eventid		number(20)		DEFAULT '0'	NOT NULL,
	source		number(10)		DEFAULT '0'	NOT NULL,
	object		number(10)		DEFAULT '0'	NOT NULL,
	objectid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	value		number(10)		DEFAULT '0'	NOT NULL,
	acknowledged		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (eventid)
)
/

CREATE INDEX events_1 on events (object,objectid,eventid)
/

CREATE INDEX events_2 on events (clock)
/

CREATE TABLE trends (
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	num		number(10)		DEFAULT '0'	NOT NULL,
	value_min		number(20,4)		DEFAULT '0.0000'	NOT NULL,
	value_avg		number(20,4)		DEFAULT '0.0000'	NOT NULL,
	value_max		number(20,4)		DEFAULT '0.0000'	NOT NULL,
	PRIMARY KEY (itemid,clock)
)
/

CREATE TABLE trends_uint (
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	num		number(10)		DEFAULT '0'	NOT NULL,
	value_min		number(20)		DEFAULT '0'	NOT NULL,
	value_avg		number(20)		DEFAULT '0'	NOT NULL,
	value_max		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (itemid,clock)
)
/

CREATE TABLE acknowledges (
	acknowledgeid		number(20)		DEFAULT '0'	NOT NULL,
	userid		number(20)		DEFAULT '0'	NOT NULL,
	eventid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	message		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (acknowledgeid)
)
/

CREATE INDEX acknowledges_1 on acknowledges (userid)
/

CREATE INDEX acknowledges_2 on acknowledges (eventid)
/

CREATE INDEX acknowledges_3 on acknowledges (clock)
/

CREATE TABLE auditlog (
	auditid		number(20)		DEFAULT '0'	NOT NULL,
	userid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	action		number(10)		DEFAULT '0'	NOT NULL,
	resourcetype		number(10)		DEFAULT '0'	NOT NULL,
	details		nvarchar2(128) 		DEFAULT '0',
	ip		nvarchar2(39)		DEFAULT '',
	resourceid		number(20)		DEFAULT '0'	NOT NULL,
	resourcename		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (auditid)
)
/

CREATE INDEX auditlog_1 on auditlog (userid,clock)
/

CREATE INDEX auditlog_2 on auditlog (clock)
/

CREATE TABLE auditlog_details (
	auditdetailid		number(20)		DEFAULT '0'	NOT NULL,
	auditid		number(20)		DEFAULT '0'	NOT NULL,
	table_name		nvarchar2(64)		DEFAULT '',
	field_name		nvarchar2(64)		DEFAULT '',
	oldvalue		nvarchar2(2048)		DEFAULT '',
	newvalue		nvarchar2(2048)		DEFAULT '',
	PRIMARY KEY (auditdetailid)
)
/

CREATE INDEX auditlog_details_1 on auditlog_details (auditid)
/

CREATE TABLE service_alarms (
	servicealarmid		number(20)		DEFAULT '0'	NOT NULL,
	serviceid		number(20)		DEFAULT '0'	NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	value		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (servicealarmid)
)
/

CREATE INDEX service_alarms_1 on service_alarms (serviceid,clock)
/

CREATE INDEX service_alarms_2 on service_alarms (clock)
/

CREATE TABLE actions (
	actionid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(255)		DEFAULT '',
	eventsource		number(10)		DEFAULT '0'	NOT NULL,
	evaltype		number(10)		DEFAULT '0'	NOT NULL,
	status		number(10)		DEFAULT '0'	NOT NULL,
	esc_period		number(10)		DEFAULT '0'	NOT NULL,
	def_shortdata		nvarchar2(255)		DEFAULT '',
	def_longdata		nvarchar2(2048)		DEFAULT '',
	recovery_msg		number(10)		DEFAULT '0'	NOT NULL,
	r_shortdata		nvarchar2(255)		DEFAULT '',
	r_longdata		nvarchar2(2048)		DEFAULT '',
	PRIMARY KEY (actionid)
)
/

CREATE INDEX actions_1 on actions (eventsource,status)
/

CREATE TABLE operations (
	operationid		number(20)		DEFAULT '0'	NOT NULL,
	actionid		number(20)		DEFAULT '0'	NOT NULL,
	operationtype		number(10)		DEFAULT '0'	NOT NULL,
	object		number(10)		DEFAULT '0'	NOT NULL,
	objectid		number(20)		DEFAULT '0'	NOT NULL,
	shortdata		nvarchar2(255)		DEFAULT '',
	longdata		nvarchar2(2048)		DEFAULT '',
	esc_period		number(10)		DEFAULT '0'	NOT NULL,
	esc_step_from		number(10)		DEFAULT '0'	NOT NULL,
	esc_step_to		number(10)		DEFAULT '0'	NOT NULL,
	default_msg		number(10)		DEFAULT '0'	NOT NULL,
	evaltype		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (operationid)
)
/

CREATE INDEX operations_1 on operations (actionid)
/

CREATE TABLE opconditions (
	opconditionid		number(20)		DEFAULT '0'	NOT NULL,
	operationid		number(20)		DEFAULT '0'	NOT NULL,
	conditiontype		number(10)		DEFAULT '0'	NOT NULL,
	operator		number(10)		DEFAULT '0'	NOT NULL,
	value		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (opconditionid)
)
/

CREATE INDEX opconditions_1 on opconditions (operationid)
/

CREATE TABLE opmediatypes (
	opmediatypeid		number(20)		DEFAULT '0'	NOT NULL,
	operationid		number(20)		DEFAULT '0'	NOT NULL,
	mediatypeid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (opmediatypeid)
)
/

CREATE UNIQUE INDEX opmediatypes_1 on opmediatypes (operationid)
/

CREATE TABLE escalations (
	escalationid		number(20)		DEFAULT '0'	NOT NULL,
	actionid		number(20)		DEFAULT '0'	NOT NULL,
	triggerid		number(20)		DEFAULT '0'	NOT NULL,
	eventid		number(20)		DEFAULT '0'	NOT NULL,
	r_eventid		number(20)		DEFAULT '0'	NOT NULL,
	nextcheck		number(10)		DEFAULT '0'	NOT NULL,
	esc_step		number(10)		DEFAULT '0'	NOT NULL,
	status		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (escalationid)
)
/

CREATE INDEX escalations_1 on escalations (actionid,triggerid)
/

CREATE INDEX escalations_2 on escalations (status,nextcheck)
/

CREATE TABLE applications (
	applicationid		number(20)		DEFAULT '0'	NOT NULL,
	hostid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(255)		DEFAULT '',
	templateid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (applicationid)
)
/

CREATE INDEX applications_1 on applications (templateid)
/

CREATE UNIQUE INDEX applications_2 on applications (hostid,name)
/

CREATE TABLE conditions (
	conditionid		number(20)		DEFAULT '0'	NOT NULL,
	actionid		number(20)		DEFAULT '0'	NOT NULL,
	conditiontype		number(10)		DEFAULT '0'	NOT NULL,
	operator		number(10)		DEFAULT '0'	NOT NULL,
	value		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (conditionid)
)
/

CREATE INDEX conditions_1 on conditions (actionid)
/

CREATE TABLE config (
	configid		number(20)		DEFAULT '0'	NOT NULL,
	alert_history		number(10)		DEFAULT '0'	NOT NULL,
	event_history		number(10)		DEFAULT '0'	NOT NULL,
	refresh_unsupported		number(10)		DEFAULT '0'	NOT NULL,
	work_period		nvarchar2(100)		DEFAULT '1-5,00:00-24:00',
	alert_usrgrpid		number(20)		DEFAULT '0'	NOT NULL,
	event_ack_enable		number(10)		DEFAULT '1'	NOT NULL,
	event_expire		number(10)		DEFAULT '7'	NOT NULL,
	event_show_max		number(10)		DEFAULT '100'	NOT NULL,
	default_theme		nvarchar2(128)		DEFAULT 'default.css',
	authentication_type		number(10)		DEFAULT '0'	NOT NULL,
	ldap_host		nvarchar2(255)		DEFAULT '',
	ldap_port		number(10)		DEFAULT 389	NOT NULL,
	ldap_base_dn		nvarchar2(255)		DEFAULT '',
	ldap_bind_dn		nvarchar2(255)		DEFAULT '',
	ldap_bind_password		nvarchar2(128)		DEFAULT '',
	ldap_search_attribute		nvarchar2(128)		DEFAULT '',
	dropdown_first_entry		number(10)		DEFAULT '1'	NOT NULL,
	dropdown_first_remember		number(10)		DEFAULT '1'	NOT NULL,
	discovery_groupid		number(20)		DEFAULT '0'	NOT NULL,
	max_in_table		number(10)		DEFAULT '50'	NOT NULL,
	search_limit		number(10)		DEFAULT '1000'	NOT NULL,
	PRIMARY KEY (configid)
)
/

CREATE TABLE functions (
	functionid		number(20)		DEFAULT '0'	NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	triggerid		number(20)		DEFAULT '0'	NOT NULL,
	lastvalue		nvarchar2(255)		,
	function		nvarchar2(12)		DEFAULT '',
	parameter		nvarchar2(255)		DEFAULT '0',
	PRIMARY KEY (functionid)
)
/

CREATE INDEX functions_1 on functions (triggerid)
/

CREATE INDEX functions_2 on functions (itemid,function,parameter)
/

CREATE TABLE graphs (
	graphid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(128)		DEFAULT '',
	width		number(10)		DEFAULT '0'	NOT NULL,
	height		number(10)		DEFAULT '0'	NOT NULL,
	yaxismin		number(20,4)		DEFAULT '0'	NOT NULL,
	yaxismax		number(20,4)		DEFAULT '0'	NOT NULL,
	templateid		number(20)		DEFAULT '0'	NOT NULL,
	show_work_period		number(10)		DEFAULT '1'	NOT NULL,
	show_triggers		number(10)		DEFAULT '1'	NOT NULL,
	graphtype		number(10)		DEFAULT '0'	NOT NULL,
	show_legend		number(10)		DEFAULT '0'	NOT NULL,
	show_3d		number(10)		DEFAULT '0'	NOT NULL,
	percent_left		number(20,4)		DEFAULT '0'	NOT NULL,
	percent_right		number(20,4)		DEFAULT '0'	NOT NULL,
	ymin_type		number(10)		DEFAULT '0'	NOT NULL,
	ymax_type		number(10)		DEFAULT '0'	NOT NULL,
	ymin_itemid		number(20)		DEFAULT '0'	NOT NULL,
	ymax_itemid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (graphid)
)
/

CREATE INDEX graphs_graphs_1 on graphs (name)
/

CREATE TABLE graphs_items (
	gitemid		number(20)		DEFAULT '0'	NOT NULL,
	graphid		number(20)		DEFAULT '0'	NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	drawtype		number(10)		DEFAULT '0'	NOT NULL,
	sortorder		number(10)		DEFAULT '0'	NOT NULL,
	color		nvarchar2(6)		DEFAULT '009600',
	yaxisside		number(10)		DEFAULT '1'	NOT NULL,
	calc_fnc		number(10)		DEFAULT '2'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	periods_cnt		number(10)		DEFAULT '5'	NOT NULL,
	PRIMARY KEY (gitemid)
)
/

CREATE INDEX graphs_items_1 on graphs_items (itemid)
/

CREATE INDEX graphs_items_2 on graphs_items (graphid)
/

CREATE TABLE graph_theme (
	graphthemeid		number(20)		DEFAULT '0'	NOT NULL,
	description		nvarchar2(64)		DEFAULT '',
	theme		nvarchar2(64)		DEFAULT '',
	backgroundcolor		nvarchar2(6)		DEFAULT 'F0F0F0',
	graphcolor		nvarchar2(6)		DEFAULT 'FFFFFF',
	graphbordercolor		nvarchar2(6)		DEFAULT '222222',
	gridcolor		nvarchar2(6)		DEFAULT 'CCCCCC',
	maingridcolor		nvarchar2(6)		DEFAULT 'AAAAAA',
	gridbordercolor		nvarchar2(6)		DEFAULT '000000',
	textcolor		nvarchar2(6)		DEFAULT '202020',
	highlightcolor		nvarchar2(6)		DEFAULT 'AA4444',
	leftpercentilecolor		nvarchar2(6)		DEFAULT '11CC11',
	rightpercentilecolor		nvarchar2(6)		DEFAULT 'CC1111',
	noneworktimecolor		nvarchar2(6)		DEFAULT 'CCCCCC',
	gridview		number(10)		DEFAULT 1	NOT NULL,
	legendview		number(10)		DEFAULT 1	NOT NULL,
	PRIMARY KEY (graphthemeid)
)
/

CREATE INDEX graph_theme_1 on graph_theme (description)
/

CREATE INDEX graph_theme_2 on graph_theme (theme)
/

CREATE TABLE groups (
	groupid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(64)		DEFAULT '',
	internal		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (groupid)
)
/

CREATE INDEX groups_1 on groups (name)
/

CREATE TABLE help_items (
	itemtype		number(10)		DEFAULT '0'	NOT NULL,
	key_		nvarchar2(255)		DEFAULT '',
	description		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (itemtype,key_)
)
/

CREATE TABLE hosts (
	hostid		number(20)		DEFAULT '0'	NOT NULL,
	proxy_hostid		number(20)		DEFAULT '0'	NOT NULL,
	host		nvarchar2(64)		DEFAULT '',
	dns		nvarchar2(64)		DEFAULT '',
	useip		number(10)		DEFAULT '1'	NOT NULL,
	ip		nvarchar2(39)		DEFAULT '127.0.0.1',
	port		number(10)		DEFAULT '10050'	NOT NULL,
	status		number(10)		DEFAULT '0'	NOT NULL,
	disable_until		number(10)		DEFAULT '0'	NOT NULL,
	error		nvarchar2(128)		DEFAULT '',
	available		number(10)		DEFAULT '0'	NOT NULL,
	errors_from		number(10)		DEFAULT '0'	NOT NULL,
	lastaccess		number(10)		DEFAULT '0'	NOT NULL,
	inbytes		number(20)		DEFAULT '0'	NOT NULL,
	outbytes		number(20)		DEFAULT '0'	NOT NULL,
	useipmi		number(10)		DEFAULT '0'	NOT NULL,
	ipmi_port		number(10)		DEFAULT '623'	NOT NULL,
	ipmi_authtype		number(10)		DEFAULT '0'	NOT NULL,
	ipmi_privilege		number(10)		DEFAULT '2'	NOT NULL,
	ipmi_username		nvarchar2(16)		DEFAULT '',
	ipmi_password		nvarchar2(20)		DEFAULT '',
	ipmi_disable_until		number(10)		DEFAULT '0'	NOT NULL,
	ipmi_available		number(10)		DEFAULT '0'	NOT NULL,
	snmp_disable_until		number(10)		DEFAULT '0'	NOT NULL,
	snmp_available		number(10)		DEFAULT '0'	NOT NULL,
	maintenanceid		number(20)		DEFAULT '0'	NOT NULL,
	maintenance_status		number(10)		DEFAULT '0'	NOT NULL,
	maintenance_type		number(10)		DEFAULT '0'	NOT NULL,
	maintenance_from		number(10)		DEFAULT '0'	NOT NULL,
	ipmi_ip		nvarchar2(64)		DEFAULT '127.0.0.1',
	ipmi_errors_from		number(10)		DEFAULT '0'	NOT NULL,
	snmp_errors_from		number(10)		DEFAULT '0'	NOT NULL,
	ipmi_error		nvarchar2(128)		DEFAULT '',
	snmp_error		nvarchar2(128)		DEFAULT '',
	PRIMARY KEY (hostid)
)
/

CREATE INDEX hosts_1 on hosts (host)
/

CREATE INDEX hosts_2 on hosts (status)
/

CREATE INDEX hosts_3 on hosts (proxy_hostid)
/

CREATE TABLE globalmacro (
	globalmacroid		number(20)		DEFAULT '0'	NOT NULL,
	macro		nvarchar2(64)		DEFAULT '',
	value		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (globalmacroid)
)
/

CREATE INDEX globalmacro_1 on globalmacro (macro)
/

CREATE TABLE hostmacro (
	hostmacroid		number(20)		DEFAULT '0'	NOT NULL,
	hostid		number(20)		DEFAULT '0'	NOT NULL,
	macro		nvarchar2(64)		DEFAULT '',
	value		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (hostmacroid)
)
/

CREATE INDEX hostmacro_1 on hostmacro (hostid,macro)
/

CREATE TABLE hosts_groups (
	hostgroupid		number(20)		DEFAULT '0'	NOT NULL,
	hostid		number(20)		DEFAULT '0'	NOT NULL,
	groupid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (hostgroupid)
)
/

CREATE INDEX hosts_groups_1 on hosts_groups (hostid,groupid)
/

CREATE INDEX hosts_groups_2 on hosts_groups (groupid)
/

CREATE TABLE hosts_profiles (
	hostid		number(20)		DEFAULT '0'	NOT NULL,
	devicetype		nvarchar2(64)		DEFAULT '',
	name		nvarchar2(64)		DEFAULT '',
	os		nvarchar2(64)		DEFAULT '',
	serialno		nvarchar2(64)		DEFAULT '',
	tag		nvarchar2(64)		DEFAULT '',
	macaddress		nvarchar2(64)		DEFAULT '',
	hardware		nvarchar2(2048)		DEFAULT '',
	software		nvarchar2(2048)		DEFAULT '',
	contact		nvarchar2(2048)		DEFAULT '',
	location		nvarchar2(2048)		DEFAULT '',
	notes		nvarchar2(2048)		DEFAULT '',
	PRIMARY KEY (hostid)
)
/

CREATE TABLE hosts_profiles_ext (
	hostid		number(20)		DEFAULT '0'	NOT NULL,
	device_alias		nvarchar2(64)		DEFAULT '',
	device_type		nvarchar2(64)		DEFAULT '',
	device_chassis		nvarchar2(64)		DEFAULT '',
	device_os		nvarchar2(64)		DEFAULT '',
	device_os_short		nvarchar2(64)		DEFAULT '',
	device_hw_arch		nvarchar2(32)		DEFAULT '',
	device_serial		nvarchar2(64)		DEFAULT '',
	device_model		nvarchar2(64)		DEFAULT '',
	device_tag		nvarchar2(64)		DEFAULT '',
	device_vendor		nvarchar2(64)		DEFAULT '',
	device_contract		nvarchar2(64)		DEFAULT '',
	device_who		nvarchar2(64)		DEFAULT '',
	device_status		nvarchar2(64)		DEFAULT '',
	device_app_01		nvarchar2(64)		DEFAULT '',
	device_app_02		nvarchar2(64)		DEFAULT '',
	device_app_03		nvarchar2(64)		DEFAULT '',
	device_app_04		nvarchar2(64)		DEFAULT '',
	device_app_05		nvarchar2(64)		DEFAULT '',
	device_url_1		nvarchar2(255)		DEFAULT '',
	device_url_2		nvarchar2(255)		DEFAULT '',
	device_url_3		nvarchar2(255)		DEFAULT '',
	device_networks		nvarchar2(2048)		DEFAULT '',
	device_notes		nvarchar2(2048)		DEFAULT '',
	device_hardware		nvarchar2(2048)		DEFAULT '',
	device_software		nvarchar2(2048)		DEFAULT '',
	ip_subnet_mask		nvarchar2(39)		DEFAULT '',
	ip_router		nvarchar2(39)		DEFAULT '',
	ip_macaddress		nvarchar2(64)		DEFAULT '',
	oob_ip		nvarchar2(39)		DEFAULT '',
	oob_subnet_mask		nvarchar2(39)		DEFAULT '',
	oob_router		nvarchar2(39)		DEFAULT '',
	date_hw_buy		nvarchar2(64)		DEFAULT '',
	date_hw_install		nvarchar2(64)		DEFAULT '',
	date_hw_expiry		nvarchar2(64)		DEFAULT '',
	date_hw_decomm		nvarchar2(64)		DEFAULT '',
	site_street_1		nvarchar2(128)		DEFAULT '',
	site_street_2		nvarchar2(128)		DEFAULT '',
	site_street_3		nvarchar2(128)		DEFAULT '',
	site_city		nvarchar2(128)		DEFAULT '',
	site_state		nvarchar2(64)		DEFAULT '',
	site_country		nvarchar2(64)		DEFAULT '',
	site_zip		nvarchar2(64)		DEFAULT '',
	site_rack		nvarchar2(128)		DEFAULT '',
	site_notes		nvarchar2(2048)		DEFAULT '',
	poc_1_name		nvarchar2(128)		DEFAULT '',
	poc_1_email		nvarchar2(128)		DEFAULT '',
	poc_1_phone_1		nvarchar2(64)		DEFAULT '',
	poc_1_phone_2		nvarchar2(64)		DEFAULT '',
	poc_1_cell		nvarchar2(64)		DEFAULT '',
	poc_1_screen		nvarchar2(64)		DEFAULT '',
	poc_1_notes		nvarchar2(2048)		DEFAULT '',
	poc_2_name		nvarchar2(128)		DEFAULT '',
	poc_2_email		nvarchar2(128)		DEFAULT '',
	poc_2_phone_1		nvarchar2(64)		DEFAULT '',
	poc_2_phone_2		nvarchar2(64)		DEFAULT '',
	poc_2_cell		nvarchar2(64)		DEFAULT '',
	poc_2_screen		nvarchar2(64)		DEFAULT '',
	poc_2_notes		nvarchar2(2048)		DEFAULT '',
	PRIMARY KEY (hostid)
)
/

CREATE TABLE hosts_templates (
	hosttemplateid		number(20)		DEFAULT '0'	NOT NULL,
	hostid		number(20)		DEFAULT '0'	NOT NULL,
	templateid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (hosttemplateid)
)
/

CREATE UNIQUE INDEX hosts_templates_1 on hosts_templates (hostid,templateid)
/

CREATE INDEX hosts_templates_2 on hosts_templates (templateid)
/

CREATE TABLE housekeeper (
	housekeeperid		number(20)		DEFAULT '0'	NOT NULL,
	tablename		nvarchar2(64)		DEFAULT '',
	field		nvarchar2(64)		DEFAULT '',
	value		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (housekeeperid)
)
/

CREATE TABLE images (
	imageid		number(20)		DEFAULT '0'	NOT NULL,
	imagetype		number(10)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(64)		DEFAULT '0',
	image		blob		DEFAULT ''	NOT NULL,
	PRIMARY KEY (imageid)
)
/

CREATE INDEX images_1 on images (imagetype,name)
/

CREATE TABLE items (
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	snmp_community		nvarchar2(64)		DEFAULT '',
	snmp_oid		nvarchar2(255)		DEFAULT '',
	snmp_port		number(10)		DEFAULT '161'	NOT NULL,
	hostid		number(20)		DEFAULT '0'	NOT NULL,
	description		nvarchar2(255)		DEFAULT '',
	key_		nvarchar2(255)		DEFAULT '',
	delay		number(10)		DEFAULT '0'	NOT NULL,
	history		number(10)		DEFAULT '90'	NOT NULL,
	trends		number(10)		DEFAULT '365'	NOT NULL,
	lastvalue		nvarchar2(255)		,
	lastclock		number(10)			NULL,
	prevvalue		nvarchar2(255)		,
	status		number(10)		DEFAULT '0'	NOT NULL,
	value_type		number(10)		DEFAULT '0'	NOT NULL,
	trapper_hosts		nvarchar2(255)		DEFAULT '',
	units		nvarchar2(10)		DEFAULT '',
	multiplier		number(10)		DEFAULT '0'	NOT NULL,
	delta		number(10)		DEFAULT '0'	NOT NULL,
	prevorgvalue		nvarchar2(255)		,
	snmpv3_securityname		nvarchar2(64)		DEFAULT '',
	snmpv3_securitylevel		number(10)		DEFAULT '0'	NOT NULL,
	snmpv3_authpassphrase		nvarchar2(64)		DEFAULT '',
	snmpv3_privpassphrase		nvarchar2(64)		DEFAULT '',
	formula		nvarchar2(255)		DEFAULT '1',
	error		nvarchar2(128)		DEFAULT '',
	lastlogsize		number(10)		DEFAULT '0'	NOT NULL,
	logtimefmt		nvarchar2(64)		DEFAULT '',
	templateid		number(20)		DEFAULT '0'	NOT NULL,
	valuemapid		number(20)		DEFAULT '0'	NOT NULL,
	delay_flex		nvarchar2(255)		DEFAULT '',
	params		nvarchar2(2048)		DEFAULT '',
	ipmi_sensor		nvarchar2(128)		DEFAULT '',
	data_type		number(10)		DEFAULT '0'	NOT NULL,
	authtype		number(10)		DEFAULT '0'	NOT NULL,
	username		nvarchar2(64)		DEFAULT '',
	password		nvarchar2(64)		DEFAULT '',
	publickey		nvarchar2(64)		DEFAULT '',
	privatekey		nvarchar2(64)		DEFAULT '',
	mtime		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (itemid)
)
/

CREATE UNIQUE INDEX items_1 on items (hostid,key_)
/

CREATE INDEX items_3 on items (status)
/

CREATE INDEX items_4 on items (templateid)
/

CREATE TABLE items_applications (
	itemappid		number(20)		DEFAULT '0'	NOT NULL,
	applicationid		number(20)		DEFAULT '0'	NOT NULL,
	itemid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (itemappid)
)
/

CREATE INDEX items_applications_1 on items_applications (applicationid,itemid)
/

CREATE INDEX items_applications_2 on items_applications (itemid)
/

CREATE TABLE mappings (
	mappingid		number(20)		DEFAULT '0'	NOT NULL,
	valuemapid		number(20)		DEFAULT '0'	NOT NULL,
	value		nvarchar2(64)		DEFAULT '',
	newvalue		nvarchar2(64)		DEFAULT '',
	PRIMARY KEY (mappingid)
)
/

CREATE INDEX mappings_1 on mappings (valuemapid)
/

CREATE TABLE media (
	mediaid		number(20)		DEFAULT '0'	NOT NULL,
	userid		number(20)		DEFAULT '0'	NOT NULL,
	mediatypeid		number(20)		DEFAULT '0'	NOT NULL,
	sendto		nvarchar2(100)		DEFAULT '',
	active		number(10)		DEFAULT '0'	NOT NULL,
	severity		number(10)		DEFAULT '63'	NOT NULL,
	period		nvarchar2(100)		DEFAULT '1-7,00:00-23:59',
	PRIMARY KEY (mediaid)
)
/

CREATE INDEX media_1 on media (userid)
/

CREATE INDEX media_2 on media (mediatypeid)
/

CREATE TABLE media_type (
	mediatypeid		number(20)		DEFAULT '0'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	description		nvarchar2(100)		DEFAULT '',
	smtp_server		nvarchar2(255)		DEFAULT '',
	smtp_helo		nvarchar2(255)		DEFAULT '',
	smtp_email		nvarchar2(255)		DEFAULT '',
	exec_path		nvarchar2(255)		DEFAULT '',
	gsm_modem		nvarchar2(255)		DEFAULT '',
	username		nvarchar2(255)		DEFAULT '',
	passwd		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (mediatypeid)
)
/

CREATE TABLE profiles (
	profileid		number(20)		DEFAULT '0'	NOT NULL,
	userid		number(20)		DEFAULT '0'	NOT NULL,
	idx		nvarchar2(96)		DEFAULT '',
	idx2		number(20)		DEFAULT '0'	NOT NULL,
	value_id		number(20)		DEFAULT '0'	NOT NULL,
	value_int		number(10)		DEFAULT '0'	NOT NULL,
	value_str		nvarchar2(255)		DEFAULT '',
	source		nvarchar2(96)		DEFAULT '',
	type		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (profileid)
)
/

CREATE INDEX profiles_1 on profiles (userid,idx,idx2)
/

CREATE INDEX profiles_2 on profiles (userid,profileid)
/

CREATE TABLE rights (
	rightid		number(20)		DEFAULT '0'	NOT NULL,
	groupid		number(20)		DEFAULT '0'	NOT NULL,
	permission		number(10)		DEFAULT '0'	NOT NULL,
	id		number(20)			,
	PRIMARY KEY (rightid)
)
/

CREATE INDEX rights_1 on rights (groupid)
/

CREATE INDEX rights_2 on rights (id)
/

CREATE TABLE scripts (
	scriptid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(255)		DEFAULT '',
	command		nvarchar2(255)		DEFAULT '',
	host_access		number(10)		DEFAULT '2'	NOT NULL,
	usrgrpid		number(20)		DEFAULT '0'	NOT NULL,
	groupid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (scriptid)
)
/

CREATE TABLE screens (
	screenid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(255)		DEFAULT 'Screen',
	hsize		number(10)		DEFAULT '1'	NOT NULL,
	vsize		number(10)		DEFAULT '1'	NOT NULL,
	PRIMARY KEY (screenid)
)
/

CREATE TABLE screens_items (
	screenitemid		number(20)		DEFAULT '0'	NOT NULL,
	screenid		number(20)		DEFAULT '0'	NOT NULL,
	resourcetype		number(10)		DEFAULT '0'	NOT NULL,
	resourceid		number(20)		DEFAULT '0'	NOT NULL,
	width		number(10)		DEFAULT '320'	NOT NULL,
	height		number(10)		DEFAULT '200'	NOT NULL,
	x		number(10)		DEFAULT '0'	NOT NULL,
	y		number(10)		DEFAULT '0'	NOT NULL,
	colspan		number(10)		DEFAULT '0'	NOT NULL,
	rowspan		number(10)		DEFAULT '0'	NOT NULL,
	elements		number(10)		DEFAULT '25'	NOT NULL,
	valign		number(10)		DEFAULT '0'	NOT NULL,
	halign		number(10)		DEFAULT '0'	NOT NULL,
	style		number(10)		DEFAULT '0'	NOT NULL,
	url		nvarchar2(255)		DEFAULT '',
	dynamic		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (screenitemid)
)
/

CREATE TABLE services (
	serviceid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(128)		DEFAULT '',
	status		number(10)		DEFAULT '0'	NOT NULL,
	algorithm		number(10)		DEFAULT '0'	NOT NULL,
	triggerid		number(20)			,
	showsla		number(10)		DEFAULT '0'	NOT NULL,
	goodsla		number(20,4)		DEFAULT '99.9'	NOT NULL,
	sortorder		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (serviceid)
)
/

CREATE INDEX services_1 on services (triggerid)
/

CREATE TABLE services_links (
	linkid		number(20)		DEFAULT '0'	NOT NULL,
	serviceupid		number(20)		DEFAULT '0'	NOT NULL,
	servicedownid		number(20)		DEFAULT '0'	NOT NULL,
	soft		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (linkid)
)
/

CREATE INDEX services_links_links_1 on services_links (servicedownid)
/

CREATE UNIQUE INDEX services_links_links_2 on services_links (serviceupid,servicedownid)
/

CREATE TABLE sessions (
	sessionid		nvarchar2(32)		DEFAULT '',
	userid		number(20)		DEFAULT '0'	NOT NULL,
	lastaccess		number(10)		DEFAULT '0'	NOT NULL,
	status		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (sessionid)
)
/

CREATE INDEX sessions_1 on sessions (userid, status)
/

CREATE TABLE sysmaps_links (
	linkid		number(20)		DEFAULT '0'	NOT NULL,
	sysmapid		number(20)		DEFAULT '0'	NOT NULL,
	selementid1		number(20)		DEFAULT '0'	NOT NULL,
	selementid2		number(20)		DEFAULT '0'	NOT NULL,
	drawtype		number(10)		DEFAULT '0'	NOT NULL,
	color		nvarchar2(6)		DEFAULT '000000',
	label		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (linkid)
)
/

CREATE TABLE sysmaps_link_triggers (
	linktriggerid		number(20)		DEFAULT '0'	NOT NULL,
	linkid		number(20)		DEFAULT '0'	NOT NULL,
	triggerid		number(20)		DEFAULT '0'	NOT NULL,
	drawtype		number(10)		DEFAULT '0'	NOT NULL,
	color		nvarchar2(6)		DEFAULT '000000',
	PRIMARY KEY (linktriggerid)
)
/

CREATE UNIQUE INDEX sysmaps_link_triggers_1 on sysmaps_link_triggers (linkid,triggerid)
/

CREATE TABLE sysmaps_elements (
	selementid		number(20)		DEFAULT '0'	NOT NULL,
	sysmapid		number(20)		DEFAULT '0'	NOT NULL,
	elementid		number(20)		DEFAULT '0'	NOT NULL,
	elementtype		number(10)		DEFAULT '0'	NOT NULL,
	iconid_off		number(20)		DEFAULT '0'	NOT NULL,
	iconid_on		number(20)		DEFAULT '0'	NOT NULL,
	iconid_unknown		number(20)		DEFAULT '0'	NOT NULL,
	label		nvarchar2(255)		DEFAULT '',
	label_location		number(10)			NULL,
	x		number(10)		DEFAULT '0'	NOT NULL,
	y		number(10)		DEFAULT '0'	NOT NULL,
	url		nvarchar2(255)		DEFAULT '',
	iconid_disabled		number(20)		DEFAULT '0'	NOT NULL,
	iconid_maintenance		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (selementid)
)
/

CREATE TABLE sysmaps (
	sysmapid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(128)		DEFAULT '',
	width		number(10)		DEFAULT '0'	NOT NULL,
	height		number(10)		DEFAULT '0'	NOT NULL,
	backgroundid		number(20)		DEFAULT '0'	NOT NULL,
	label_type		number(10)		DEFAULT '0'	NOT NULL,
	label_location		number(10)		DEFAULT '0'	NOT NULL,
	highlight		number(10)		DEFAULT '1'	NOT NULL,
	PRIMARY KEY (sysmapid)
)
/

CREATE INDEX sysmaps_1 on sysmaps (name)
/

CREATE TABLE triggers (
	triggerid		number(20)		DEFAULT '0'	NOT NULL,
	expression		nvarchar2(255)		DEFAULT '',
	description		nvarchar2(255)		DEFAULT '',
	url		nvarchar2(255)		DEFAULT '',
	status		number(10)		DEFAULT '0'	NOT NULL,
	value		number(10)		DEFAULT '0'	NOT NULL,
	priority		number(10)		DEFAULT '0'	NOT NULL,
	lastchange		number(10)		DEFAULT '0'	NOT NULL,
	dep_level		number(10)		DEFAULT '0'	NOT NULL,
	comments		nvarchar2(2048)		DEFAULT '',
	error		nvarchar2(128)		DEFAULT '',
	templateid		number(20)		DEFAULT '0'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (triggerid)
)
/

CREATE INDEX triggers_1 on triggers (status)
/

CREATE INDEX triggers_2 on triggers (value)
/

CREATE TABLE trigger_depends (
	triggerdepid		number(20)		DEFAULT '0'	NOT NULL,
	triggerid_down		number(20)		DEFAULT '0'	NOT NULL,
	triggerid_up		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (triggerdepid)
)
/

CREATE INDEX trigger_depends_1 on trigger_depends (triggerid_down,triggerid_up)
/

CREATE INDEX trigger_depends_2 on trigger_depends (triggerid_up)
/

CREATE TABLE users (
	userid		number(20)		DEFAULT '0'	NOT NULL,
	alias		nvarchar2(100)		DEFAULT '',
	name		nvarchar2(100)		DEFAULT '',
	surname		nvarchar2(100)		DEFAULT '',
	passwd		nvarchar2(32)		DEFAULT '',
	url		nvarchar2(255)		DEFAULT '',
	autologin		number(10)		DEFAULT '0'	NOT NULL,
	autologout		number(10)		DEFAULT '900'	NOT NULL,
	lang		nvarchar2(5)		DEFAULT 'en_gb',
	refresh		number(10)		DEFAULT '30'	NOT NULL,
	type		number(10)		DEFAULT '0'	NOT NULL,
	theme		nvarchar2(128)		DEFAULT 'default.css',
	attempt_failed		number(10)		DEFAULT 0	NOT NULL,
	attempt_ip		nvarchar2(39)		DEFAULT '',
	attempt_clock		number(10)		DEFAULT 0	NOT NULL,
	rows_per_page		number(10)		DEFAULT 50	NOT NULL,
	PRIMARY KEY (userid)
)
/

CREATE INDEX users_1 on users (alias)
/

CREATE TABLE usrgrp (
	usrgrpid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(64)		DEFAULT '',
	gui_access		number(10)		DEFAULT '0'	NOT NULL,
	users_status		number(10)		DEFAULT '0'	NOT NULL,
	api_access		number(10)		DEFAULT '0'	NOT NULL,
	debug_mode		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (usrgrpid)
)
/

CREATE INDEX usrgrp_1 on usrgrp (name)
/

CREATE TABLE users_groups (
	id		number(20)		DEFAULT '0'	NOT NULL,
	usrgrpid		number(20)		DEFAULT '0'	NOT NULL,
	userid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (id)
)
/

CREATE INDEX users_groups_1 on users_groups (usrgrpid,userid)
/

CREATE TABLE valuemaps (
	valuemapid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(64)		DEFAULT '',
	PRIMARY KEY (valuemapid)
)
/

CREATE INDEX valuemaps_1 on valuemaps (name)
/

CREATE TABLE maintenances (
	maintenanceid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(128)		DEFAULT '',
	maintenance_type		number(10)		DEFAULT '0'	NOT NULL,
	description		nvarchar2(2048)		DEFAULT '',
	active_since		number(10)		DEFAULT '0'	NOT NULL,
	active_till		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (maintenanceid)
)
/

CREATE INDEX maintenances_1 on maintenances (active_since,active_till)
/

CREATE TABLE maintenances_hosts (
	maintenance_hostid		number(20)		DEFAULT '0'	NOT NULL,
	maintenanceid		number(20)		DEFAULT '0'	NOT NULL,
	hostid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (maintenance_hostid)
)
/

CREATE INDEX maintenances_hosts_1 on maintenances_hosts (maintenanceid,hostid)
/

CREATE TABLE maintenances_groups (
	maintenance_groupid		number(20)		DEFAULT '0'	NOT NULL,
	maintenanceid		number(20)		DEFAULT '0'	NOT NULL,
	groupid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (maintenance_groupid)
)
/

CREATE INDEX maintenances_groups_1 on maintenances_groups (maintenanceid,groupid)
/

CREATE TABLE maintenances_windows (
	maintenance_timeperiodid		number(20)		DEFAULT '0'	NOT NULL,
	maintenanceid		number(20)		DEFAULT '0'	NOT NULL,
	timeperiodid		number(20)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (maintenance_timeperiodid)
)
/

CREATE INDEX maintenances_windows_1 on maintenances_windows (maintenanceid,timeperiodid)
/

CREATE TABLE timeperiods (
	timeperiodid		number(20)		DEFAULT '0'	NOT NULL,
	timeperiod_type		number(10)		DEFAULT '0'	NOT NULL,
	every		number(10)		DEFAULT '0'	NOT NULL,
	month		number(10)		DEFAULT '0'	NOT NULL,
	dayofweek		number(10)		DEFAULT '0'	NOT NULL,
	day		number(10)		DEFAULT '0'	NOT NULL,
	start_time		number(10)		DEFAULT '0'	NOT NULL,
	period		number(10)		DEFAULT '0'	NOT NULL,
	start_date		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (timeperiodid)
)
/

CREATE TABLE regexps (
	regexpid		number(20)		DEFAULT '0'	NOT NULL,
	name		nvarchar2(128)		DEFAULT '',
	test_string		nvarchar2(2048)		DEFAULT '',
	PRIMARY KEY (regexpid)
)
/

CREATE INDEX regexps_1 on regexps (name)
/

CREATE TABLE user_history (
	userhistoryid		number(20)		DEFAULT '0'	NOT NULL,
	userid		number(20)		DEFAULT '0'	NOT NULL,
	title1		nvarchar2(255)		DEFAULT '',
	url1		nvarchar2(255)		DEFAULT '',
	title2		nvarchar2(255)		DEFAULT '',
	url2		nvarchar2(255)		DEFAULT '',
	title3		nvarchar2(255)		DEFAULT '',
	url3		nvarchar2(255)		DEFAULT '',
	title4		nvarchar2(255)		DEFAULT '',
	url4		nvarchar2(255)		DEFAULT '',
	title5		nvarchar2(255)		DEFAULT '',
	url5		nvarchar2(255)		DEFAULT '',
	PRIMARY KEY (userhistoryid)
)
/

CREATE UNIQUE INDEX user_history_1 on user_history (userid)
/

CREATE TABLE expressions (
	expressionid		number(20)		DEFAULT '0'	NOT NULL,
	regexpid		number(20)		DEFAULT '0'	NOT NULL,
	expression		nvarchar2(255)		DEFAULT '',
	expression_type		number(10)		DEFAULT '0'	NOT NULL,
	exp_delimiter		nvarchar2(1)		DEFAULT '',
	case_sensitive		number(10)		DEFAULT '0'	NOT NULL,
	PRIMARY KEY (expressionid)
)
/

CREATE INDEX expressions_1 on expressions (regexpid)
/

CREATE TABLE autoreg_host (
	autoreg_hostid		number(20)		DEFAULT '0'	NOT NULL,
	proxy_hostid		number(20)		DEFAULT '0'	NOT NULL,
	host		nvarchar2(64)		DEFAULT '',
	PRIMARY KEY (autoreg_hostid)
)
/

CREATE INDEX autoreg_host_1 on autoreg_host (proxy_hostid,host)
/

CREATE TABLE proxy_autoreg_host (
	id		number(20)			NOT NULL,
	clock		number(10)		DEFAULT '0'	NOT NULL,
	host		nvarchar2(64)		DEFAULT '',
	PRIMARY KEY (id)
)
/

CREATE INDEX proxy_autoreg_host_1 on proxy_autoreg_host (clock)
/

CREATE SEQUENCE proxy_autoreg_host_seq
START WITH 1
INCREMENT BY 1
NOMAXVALUE
/

CREATE TRIGGER proxy_autoreg_host_tr
BEFORE INSERT ON proxy_autoreg_host
FOR EACH ROW
BEGIN
SELECT proxy_history_seq.nextval INTO :new.id FROM dual;
END;
/

