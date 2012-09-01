/* 
** ZABBIX
** Copyright (C) 2000-2005 SIA Zabbix
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
**/

#include "common.h"
#include "dbschema.h"

ZBX_TABLE	tables[]={
	{"slideshows",	"slideshowid",	ZBX_SYNC,
		{
		{"slideshowid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"delay",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"slides",	"slideid",	ZBX_SYNC,
		{
		{"slideid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"slideshowid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"slideshows"},
		{"screenid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"screens"},
		{"step",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"delay",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"drules",	"druleid",	ZBX_SYNC,
		{
		{"druleid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"proxy_hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"hosts"},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"iprange",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"delay",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"nextcheck",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"unique_dcheckid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	"dchecks"},
		{0}
		}
	},
	{"dchecks",	"dcheckid",	ZBX_SYNC,
		{
		{"dcheckid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"druleid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	"drules"},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"key_",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmp_community",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"ports",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmpv3_securityname",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmpv3_securitylevel",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmpv3_authpassphrase",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmpv3_privpassphrase",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{0}
		}
	},
	{"dhosts",	"dhostid",	ZBX_SYNC,
		{
		{"dhostid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"druleid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"drules"},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"lastup",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"lastdown",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"dservices",	"dserviceid",	ZBX_SYNC,
		{
		{"dserviceid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"dhostid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"dhosts"},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"key_",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"value",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"port",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"lastup",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"lastdown",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"dcheckid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"dchecks"},
		{"ip",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"ids",	"nodeid,table_name,field_name",	0,
		{
		{"nodeid",	ZBX_TYPE_INT,	ZBX_NOTNULL,	"nodes"},
		{"table_name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"field_name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"nextid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"httptest",	"httptestid",	ZBX_SYNC,
		{
		{"httptestid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"applicationid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"applications"},
		{"lastcheck",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"nextcheck",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"curstate",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"curstep",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"lastfailedstep",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"delay",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"macros",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"agent",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"time",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"error",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"authentication",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"http_user",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"http_password",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"httpstep",	"httpstepid",	ZBX_SYNC,
		{
		{"httpstepid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"httptestid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"httptest"},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"no",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"url",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"timeout",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"posts",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"required",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"status_codes",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"httpstepitem",	"httpstepitemid",	ZBX_SYNC,
		{
		{"httpstepitemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"httpstepid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"httpstep"},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"items"},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"httptestitem",	"httptestitemid",	ZBX_SYNC,
		{
		{"httptestitemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"httptestid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"httptest"},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"items"},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"nodes",	"nodeid",	0,
		{
		{"nodeid",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"timezone",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"ip",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"port",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"slave_history",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"slave_trends",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"nodetype",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"masterid",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"node_cksum",	"",	0,
		{
		{"nodeid",	ZBX_TYPE_INT,	ZBX_NOTNULL,	"nodes"},
		{"tablename",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"recordid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"cksumtype",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"cksum",	ZBX_TYPE_TEXT,	ZBX_NOTNULL,	NULL},
		{"sync",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"services_times",	"timeid",	ZBX_SYNC,
		{
		{"timeid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"serviceid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"services"},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ts_from",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ts_to",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"note",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"alerts",	"alertid",	ZBX_HISTORY,
		{
		{"alertid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"actionid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"actions"},
		{"eventid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"events"},
		{"userid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"users"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"mediatypeid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"media_type"},
		{"sendto",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"subject",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"message",	ZBX_TYPE_BLOB,	ZBX_NOTNULL,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"retries",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"error",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"nextcheck",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"esc_step",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"alerttype",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"history",	"",	0,
		{
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"history_sync",	"id",	ZBX_HISTORY_SYNC,
		{
		{"id",	ZBX_TYPE_UINT,	ZBX_NOTNULL,	NULL},
		{"nodeid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"nodes"},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_HISTORY_SYNC,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_HISTORY_SYNC,	NULL},
		{"value",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL | ZBX_HISTORY_SYNC,	NULL},
		{0}
		}
	},
	{"history_uint",	"",	0,
		{
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value",	ZBX_TYPE_UINT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"history_uint_sync",	"id",	ZBX_HISTORY_SYNC,
		{
		{"id",	ZBX_TYPE_UINT,	ZBX_NOTNULL,	NULL},
		{"nodeid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"nodes"},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_HISTORY_SYNC,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_HISTORY_SYNC,	NULL},
		{"value",	ZBX_TYPE_UINT,	ZBX_NOTNULL | ZBX_HISTORY_SYNC,	NULL},
		{0}
		}
	},
	{"history_str",	"",	0,
		{
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"history_str_sync",	"id",	ZBX_HISTORY_SYNC,
		{
		{"id",	ZBX_TYPE_UINT,	ZBX_NOTNULL,	NULL},
		{"nodeid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"nodes"},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_HISTORY_SYNC,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_HISTORY_SYNC,	NULL},
		{"value",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_HISTORY_SYNC,	NULL},
		{0}
		}
	},
	{"history_log",	"id",	ZBX_HISTORY,
		{
		{"id",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"timestamp",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"source",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"severity",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value",	ZBX_TYPE_TEXT,	ZBX_NOTNULL,	NULL},
		{"logeventid",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"history_text",	"id",	ZBX_HISTORY,
		{
		{"id",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value",	ZBX_TYPE_TEXT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"proxy_history",	"id",	0,
		{
		{"id",	ZBX_TYPE_UINT,	ZBX_NOTNULL,	NULL},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"timestamp",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"source",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"severity",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value",	ZBX_TYPE_TEXT,	ZBX_NOTNULL,	NULL},
		{"logeventid",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"proxy_dhistory",	"id",	0,
		{
		{"id",	ZBX_TYPE_UINT,	ZBX_NOTNULL,	NULL},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"druleid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"drules"},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"ip",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"port",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"key_",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"value",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"dcheckid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"dchecks"},
		{0}
		}
	},
	{"events",	"eventid",	ZBX_HISTORY,
		{
		{"eventid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"source",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"object",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"objectid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"acknowledged",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"trends",	"itemid,clock",	0,
		{
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"num",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value_min",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	NULL},
		{"value_avg",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	NULL},
		{"value_max",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"trends_uint",	"itemid,clock",	0,
		{
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"items"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"num",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value_min",	ZBX_TYPE_UINT,	ZBX_NOTNULL,	NULL},
		{"value_avg",	ZBX_TYPE_UINT,	ZBX_NOTNULL,	NULL},
		{"value_max",	ZBX_TYPE_UINT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"acknowledges",	"acknowledgeid",	ZBX_HISTORY,
		{
		{"acknowledgeid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"userid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"users"},
		{"eventid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"events"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"message",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"auditlog",	"auditid",	ZBX_HISTORY,
		{
		{"auditid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"userid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"users"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"action",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"resourcetype",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"details",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"ip",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"resourceid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"resourcename",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"auditlog_details",	"auditdetailid",	ZBX_HISTORY,
		{
		{"auditdetailid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"auditid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"auditlog"},
		{"table_name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"field_name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"oldvalue",	ZBX_TYPE_BLOB,	ZBX_NOTNULL,	NULL},
		{"newvalue",	ZBX_TYPE_BLOB,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"service_alarms",	"servicealarmid",	ZBX_HISTORY,
		{
		{"servicealarmid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"serviceid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"services"},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"actions",	"actionid",	ZBX_SYNC,
		{
		{"actionid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"eventsource",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"evaltype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"esc_period",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"def_shortdata",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"def_longdata",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"recovery_msg",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"r_shortdata",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"r_longdata",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"operations",	"operationid",	ZBX_SYNC,
		{
		{"operationid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"actionid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"actions"},
		{"operationtype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"object",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"objectid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"shortdata",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"longdata",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"esc_period",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"esc_step_from",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"esc_step_to",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"default_msg",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"evaltype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"opconditions",	"opconditionid",	ZBX_SYNC,
		{
		{"opconditionid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"operationid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"operations"},
		{"conditiontype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"operator",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"value",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"opmediatypes",	"opmediatypeid",	ZBX_SYNC,
		{
		{"opmediatypeid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"operationid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"operations"},
		{"mediatypeid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"media_type"},
		{0}
		}
	},
	{"escalations",	"escalationid",	0,
		{
		{"escalationid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"actionid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"actions"},
		{"triggerid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"triggers"},
		{"eventid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"events"},
		{"r_eventid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"events"},
		{"nextcheck",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"esc_step",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"applications",	"applicationid",	ZBX_SYNC,
		{
		{"applicationid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"hosts"},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"templateid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"applications"},
		{0}
		}
	},
	{"conditions",	"conditionid",	ZBX_SYNC,
		{
		{"conditionid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"actionid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"actions"},
		{"conditiontype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"operator",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"value",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"config",	"configid",	ZBX_SYNC,
		{
		{"configid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"alert_history",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"event_history",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"refresh_unsupported",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"work_period",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"alert_usrgrpid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"usrgrp"},
		{"event_ack_enable",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"event_expire",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"event_show_max",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"default_theme",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"authentication_type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ldap_host",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ldap_port",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ldap_base_dn",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ldap_bind_dn",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ldap_bind_password",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ldap_search_attribute",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"dropdown_first_entry",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"dropdown_first_remember",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"discovery_groupid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"groups"},
		{"max_in_table",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"search_limit",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"functions",	"functionid",	ZBX_SYNC,
		{
		{"functionid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"items"},
		{"triggerid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"triggers"},
		{"lastvalue",	ZBX_TYPE_CHAR,	0,	NULL},
		{"function",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"parameter",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"graphs",	"graphid",	ZBX_SYNC,
		{
		{"graphid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"width",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"height",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"yaxismin",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"yaxismax",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"templateid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"graphs"},
		{"show_work_period",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"show_triggers",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"graphtype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"show_legend",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"show_3d",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"percent_left",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"percent_right",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ymin_type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ymax_type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ymin_itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"items"},
		{"ymax_itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"items"},
		{0}
		}
	},
	{"graphs_items",	"gitemid",	ZBX_SYNC,
		{
		{"gitemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"graphid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"graphs"},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"items"},
		{"drawtype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"sortorder",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"color",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"yaxisside",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"calc_fnc",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"periods_cnt",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"graph_theme",	"graphthemeid",	0,
		{
		{"graphthemeid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"description",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"theme",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"backgroundcolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"graphcolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"graphbordercolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"gridcolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"maingridcolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"gridbordercolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"textcolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"highlightcolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"leftpercentilecolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"rightpercentilecolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"noneworktimecolor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"gridview",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"legendview",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"groups",	"groupid",	ZBX_SYNC,
		{
		{"groupid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"internal",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"help_items",	"itemtype,key_",	0,
		{
		{"itemtype",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"key_",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"description",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"hosts",	"hostid",	ZBX_SYNC,
		{
		{"hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"proxy_hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"hosts"},
		{"host",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"dns",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"useip",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"ip",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"port",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"disable_until",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"error",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"available",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"errors_from",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"lastaccess",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"inbytes",	ZBX_TYPE_UINT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"outbytes",	ZBX_TYPE_UINT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"useipmi",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"ipmi_port",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"ipmi_authtype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"ipmi_privilege",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"ipmi_username",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"ipmi_password",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"ipmi_disable_until",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"ipmi_available",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"snmp_disable_until",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"snmp_available",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"maintenanceid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"maintenances"},
		{"maintenance_status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"maintenance_type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"maintenance_from",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ipmi_ip",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"ipmi_errors_from",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"snmp_errors_from",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"ipmi_error",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"snmp_error",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"globalmacro",	"globalmacroid",	ZBX_SYNC,
		{
		{"globalmacroid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"macro",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"value",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{0}
		}
	},
	{"hostmacro",	"hostmacroid",	ZBX_SYNC,
		{
		{"hostmacroid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	"hosts"},
		{"macro",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"value",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{0}
		}
	},
	{"hosts_groups",	"hostgroupid",	ZBX_SYNC,
		{
		{"hostgroupid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"hosts"},
		{"groupid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"groups"},
		{0}
		}
	},
	{"hosts_profiles",	"hostid",	ZBX_SYNC,
		{
		{"hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"hosts"},
		{"devicetype",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"os",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"serialno",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"tag",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"macaddress",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"hardware",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"software",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"contact",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"location",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"notes",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"hosts_profiles_ext",	"hostid",	ZBX_SYNC,
		{
		{"hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"hosts"},
		{"device_alias",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_type",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_chassis",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_os",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_os_short",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_hw_arch",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_serial",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_model",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_tag",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_vendor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_contract",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_who",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_status",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_app_01",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_app_02",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_app_03",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_app_04",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_app_05",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_url_1",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_url_2",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_url_3",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_networks",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_notes",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_hardware",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"device_software",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ip_subnet_mask",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ip_router",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"ip_macaddress",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"oob_ip",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"oob_subnet_mask",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"oob_router",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"date_hw_buy",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"date_hw_install",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"date_hw_expiry",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"date_hw_decomm",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"site_street_1",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"site_street_2",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"site_street_3",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"site_city",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"site_state",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"site_country",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"site_zip",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"site_rack",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"site_notes",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_1_name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_1_email",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_1_phone_1",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_1_phone_2",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_1_cell",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_1_screen",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_1_notes",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_2_name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_2_email",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_2_phone_1",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_2_phone_2",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_2_cell",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_2_screen",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"poc_2_notes",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"hosts_templates",	"hosttemplateid",	ZBX_SYNC,
		{
		{"hosttemplateid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	"hosts"},
		{"templateid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	"hosts"},
		{0}
		}
	},
	{"housekeeper",	"housekeeperid",	0,
		{
		{"housekeeperid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"tablename",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"field",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"value",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"items"},
		{0}
		}
	},
	{"images",	"imageid",	ZBX_SYNC,
		{
		{"imageid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"imagetype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"image",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"items",	"itemid",	ZBX_SYNC,
		{
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmp_community",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmp_oid",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmp_port",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	"hosts"},
		{"description",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"key_",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"delay",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"history",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"trends",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"lastvalue",	ZBX_TYPE_CHAR,	0,	NULL},
		{"lastclock",	ZBX_TYPE_INT,	0,	NULL},
		{"prevvalue",	ZBX_TYPE_CHAR,	0,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"value_type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"trapper_hosts",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"units",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"multiplier",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"delta",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"prevorgvalue",	ZBX_TYPE_CHAR,	0,	NULL},
		{"snmpv3_securityname",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmpv3_securitylevel",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmpv3_authpassphrase",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"snmpv3_privpassphrase",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"formula",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"error",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"lastlogsize",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"logtimefmt",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"templateid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	"items"},
		{"valuemapid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	"valuemaps"},
		{"delay_flex",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"params",	ZBX_TYPE_TEXT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"ipmi_sensor",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"data_type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"authtype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"username",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"password",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"publickey",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"privatekey",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"mtime",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"items_applications",	"itemappid",	ZBX_SYNC,
		{
		{"itemappid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"applicationid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"applications"},
		{"itemid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"items"},
		{0}
		}
	},
	{"mappings",	"mappingid",	ZBX_SYNC,
		{
		{"mappingid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"valuemapid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"valuemaps"},
		{"value",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"newvalue",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"media",	"mediaid",	ZBX_SYNC,
		{
		{"mediaid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"userid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"users"},
		{"mediatypeid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"media_type"},
		{"sendto",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"active",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"severity",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"period",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"media_type",	"mediatypeid",	ZBX_SYNC,
		{
		{"mediatypeid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"description",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"smtp_server",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"smtp_helo",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"smtp_email",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"exec_path",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"gsm_modem",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"username",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"passwd",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"profiles",	"profileid",	0,
		{
		{"profileid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"userid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"users"},
		{"idx",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"idx2",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"value_id",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"value_int",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"value_str",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"source",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"rights",	"rightid",	ZBX_SYNC,
		{
		{"rightid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"groupid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"usrgrp"},
		{"permission",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"id",	ZBX_TYPE_ID,	ZBX_SYNC,	"groups"},
		{0}
		}
	},
	{"scripts",	"scriptid",	ZBX_SYNC,
		{
		{"scriptid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"command",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"host_access",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"usrgrpid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"usrgrp"},
		{"groupid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"groups"},
		{0}
		}
	},
	{"screens",	"screenid",	ZBX_SYNC,
		{
		{"screenid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"hsize",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"vsize",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"screens_items",	"screenitemid",	ZBX_SYNC,
		{
		{"screenitemid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"screenid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"screens"},
		{"resourcetype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"resourceid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"width",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"height",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"x",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"y",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"colspan",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"rowspan",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"elements",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"valign",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"halign",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"style",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"url",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"dynamic",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"services",	"serviceid",	ZBX_SYNC,
		{
		{"serviceid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"algorithm",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"triggerid",	ZBX_TYPE_ID,	ZBX_SYNC,	"triggers"},
		{"showsla",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"goodsla",	ZBX_TYPE_FLOAT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"sortorder",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"services_links",	"linkid",	ZBX_SYNC,
		{
		{"linkid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"serviceupid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"services"},
		{"servicedownid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"services"},
		{"soft",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"sessions",	"sessionid",	0,
		{
		{"sessionid",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{"userid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	"users"},
		{"lastaccess",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{"sysmaps_links",	"linkid",	ZBX_SYNC,
		{
		{"linkid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"sysmapid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"sysmaps"},
		{"selementid1",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"sysmaps_elements"},
		{"selementid2",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"sysmaps_elements"},
		{"drawtype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"color",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"label",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"sysmaps_link_triggers",	"linktriggerid",	ZBX_SYNC,
		{
		{"linktriggerid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"linkid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"sysmaps_links"},
		{"triggerid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"triggers"},
		{"drawtype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"color",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"sysmaps_elements",	"selementid",	ZBX_SYNC,
		{
		{"selementid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"sysmapid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"sysmaps"},
		{"elementid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"elementtype",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"iconid_off",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"images"},
		{"iconid_on",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"images"},
		{"iconid_unknown",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"images"},
		{"label",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"label_location",	ZBX_TYPE_INT,	ZBX_SYNC,	NULL},
		{"x",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"y",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"url",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"iconid_disabled",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"images"},
		{"iconid_maintenance",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"images"},
		{0}
		}
	},
	{"sysmaps",	"sysmapid",	ZBX_SYNC,
		{
		{"sysmapid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"width",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"height",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"backgroundid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"images"},
		{"label_type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"label_location",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"highlight",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"triggers",	"triggerid",	ZBX_SYNC,
		{
		{"triggerid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"expression",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"description",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"url",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"value",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"priority",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"lastchange",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"dep_level",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"comments",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"error",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"templateid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"triggers"},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"trigger_depends",	"triggerdepid",	ZBX_SYNC,
		{
		{"triggerdepid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"triggerid_down",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"triggers"},
		{"triggerid_up",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"triggers"},
		{0}
		}
	},
	{"users",	"userid",	ZBX_SYNC,
		{
		{"userid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"alias",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"surname",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"passwd",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"url",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"autologin",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"autologout",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"lang",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"refresh",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"theme",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"attempt_failed",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"attempt_ip",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"attempt_clock",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"rows_per_page",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"usrgrp",	"usrgrpid",	ZBX_SYNC,
		{
		{"usrgrpid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"gui_access",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"users_status",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"api_access",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"debug_mode",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"users_groups",	"id",	ZBX_SYNC,
		{
		{"id",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"usrgrpid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"usrgrp"},
		{"userid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"users"},
		{0}
		}
	},
	{"valuemaps",	"valuemapid",	ZBX_SYNC,
		{
		{"valuemapid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"maintenances",	"maintenanceid",	ZBX_SYNC,
		{
		{"maintenanceid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"maintenance_type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"description",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"active_since",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"active_till",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"maintenances_hosts",	"maintenance_hostid",	ZBX_SYNC,
		{
		{"maintenance_hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"maintenanceid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"maintenances"},
		{"hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"hosts"},
		{0}
		}
	},
	{"maintenances_groups",	"maintenance_groupid",	ZBX_SYNC,
		{
		{"maintenance_groupid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"maintenanceid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"maintenances"},
		{"groupid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"groups"},
		{0}
		}
	},
	{"maintenances_windows",	"maintenance_timeperiodid",	ZBX_SYNC,
		{
		{"maintenance_timeperiodid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"maintenanceid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"maintenances"},
		{"timeperiodid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"timeperiods"},
		{0}
		}
	},
	{"timeperiods",	"timeperiodid",	ZBX_SYNC,
		{
		{"timeperiodid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"timeperiod_type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"every",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"month",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"dayofweek",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"day",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"start_time",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"period",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"start_date",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"regexps",	"regexpid",	ZBX_SYNC,
		{
		{"regexpid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"name",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"test_string",	ZBX_TYPE_BLOB,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"user_history",	"userhistoryid",	ZBX_SYNC,
		{
		{"userhistoryid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"userid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"users"},
		{"title1",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"url1",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"title2",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"url2",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"title3",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"url3",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"title4",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"url4",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"title5",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{"url5",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"expressions",	"expressionid",	ZBX_SYNC,
		{
		{"expressionid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"regexpid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	"regexps"},
		{"expression",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"expression_type",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"exp_delimiter",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{"case_sensitive",	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_SYNC | ZBX_PROXY,	NULL},
		{0}
		}
	},
	{"autoreg_host",	"autoreg_hostid",	ZBX_SYNC,
		{
		{"autoreg_hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL,	NULL},
		{"proxy_hostid",	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_SYNC,	"hosts"},
		{"host",	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_SYNC,	NULL},
		{0}
		}
	},
	{"proxy_autoreg_host",	"id",	0,
		{
		{"id",	ZBX_TYPE_UINT,	ZBX_NOTNULL,	NULL},
		{"clock",	ZBX_TYPE_INT,	ZBX_NOTNULL,	NULL},
		{"host",	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	NULL},
		{0}
		}
	},
	{0}
};

#ifdef HAVE_SQLITE3
const char *db_schema= {"\
BEGIN TRANSACTION;\
CREATE TABLE slideshows (\
 slideshowid bigint DEFAULT '0' NOT NULL,\
 name varchar(255) DEFAULT '' NOT NULL,\
 delay integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (slideshowid)\
);\
CREATE TABLE slides (\
 slideid bigint DEFAULT '0' NOT NULL,\
 slideshowid bigint DEFAULT '0' NOT NULL,\
 screenid bigint DEFAULT '0' NOT NULL,\
 step integer DEFAULT '0' NOT NULL,\
 delay integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (slideid)\
);\
CREATE INDEX slides_slides_1 on slides (slideshowid);\
CREATE TABLE drules (\
 druleid bigint DEFAULT '0' NOT NULL,\
 proxy_hostid bigint DEFAULT '0' NOT NULL,\
 name varchar(255) DEFAULT '' NOT NULL,\
 iprange varchar(255) DEFAULT '' NOT NULL,\
 delay integer DEFAULT '0' NOT NULL,\
 nextcheck integer DEFAULT '0' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 unique_dcheckid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (druleid)\
);\
CREATE TABLE dchecks (\
 dcheckid bigint DEFAULT '0' NOT NULL,\
 druleid bigint DEFAULT '0' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 key_ varchar(255) DEFAULT '0' NOT NULL,\
 snmp_community varchar(255) DEFAULT '0' NOT NULL,\
 ports varchar(255) DEFAULT '0' NOT NULL,\
 snmpv3_securityname varchar(64) DEFAULT '' NOT NULL,\
 snmpv3_securitylevel integer DEFAULT '0' NOT NULL,\
 snmpv3_authpassphrase varchar(64) DEFAULT '' NOT NULL,\
 snmpv3_privpassphrase varchar(64) DEFAULT '' NOT NULL,\
 PRIMARY KEY (dcheckid)\
);\
CREATE INDEX dchecks_1 on dchecks (druleid);\
CREATE TABLE dhosts (\
 dhostid bigint DEFAULT '0' NOT NULL,\
 druleid bigint DEFAULT '0' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 lastup integer DEFAULT '0' NOT NULL,\
 lastdown integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (dhostid)\
);\
CREATE INDEX dhosts_1 on dhosts (druleid);\
CREATE TABLE dservices (\
 dserviceid bigint DEFAULT '0' NOT NULL,\
 dhostid bigint DEFAULT '0' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 key_ varchar(255) DEFAULT '0' NOT NULL,\
 value varchar(255) DEFAULT '0' NOT NULL,\
 port integer DEFAULT '0' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 lastup integer DEFAULT '0' NOT NULL,\
 lastdown integer DEFAULT '0' NOT NULL,\
 dcheckid bigint DEFAULT '0' NOT NULL,\
 ip varchar(39) DEFAULT '' NOT NULL,\
 PRIMARY KEY (dserviceid)\
);\
CREATE UNIQUE INDEX dservices_1 on dservices (dcheckid,type,key_,ip,port);\
CREATE INDEX dservices_2 on dservices (dhostid);\
CREATE TABLE ids (\
 nodeid integer DEFAULT '0' NOT NULL,\
 table_name varchar(64) DEFAULT '' NOT NULL,\
 field_name varchar(64) DEFAULT '' NOT NULL,\
 nextid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (nodeid,table_name,field_name)\
);\
CREATE TABLE httptest (\
 httptestid bigint DEFAULT '0' NOT NULL,\
 name varchar(64) DEFAULT '' NOT NULL,\
 applicationid bigint DEFAULT '0' NOT NULL,\
 lastcheck integer DEFAULT '0' NOT NULL,\
 nextcheck integer DEFAULT '0' NOT NULL,\
 curstate integer DEFAULT '0' NOT NULL,\
 curstep integer DEFAULT '0' NOT NULL,\
 lastfailedstep integer DEFAULT '0' NOT NULL,\
 delay integer DEFAULT '60' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 macros blob DEFAULT '' NOT NULL,\
 agent varchar(255) DEFAULT '' NOT NULL,\
 time double(16,4) DEFAULT '0' NOT NULL,\
 error varchar(255) DEFAULT '' NOT NULL,\
 authentication integer DEFAULT '0' NOT NULL,\
 http_user varchar(64) DEFAULT '' NOT NULL,\
 http_password varchar(64) DEFAULT '' NOT NULL,\
 PRIMARY KEY (httptestid)\
);\
CREATE INDEX httptest_httptest_1 on httptest (applicationid);\
CREATE INDEX httptest_2 on httptest (name);\
CREATE INDEX httptest_3 on httptest (status);\
CREATE TABLE httpstep (\
 httpstepid bigint DEFAULT '0' NOT NULL,\
 httptestid bigint DEFAULT '0' NOT NULL,\
 name varchar(64) DEFAULT '' NOT NULL,\
 no integer DEFAULT '0' NOT NULL,\
 url varchar(255) DEFAULT '' NOT NULL,\
 timeout integer DEFAULT '30' NOT NULL,\
 posts blob DEFAULT '' NOT NULL,\
 required varchar(255) DEFAULT '' NOT NULL,\
 status_codes varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (httpstepid)\
);\
CREATE INDEX httpstep_httpstep_1 on httpstep (httptestid);\
CREATE TABLE httpstepitem (\
 httpstepitemid bigint DEFAULT '0' NOT NULL,\
 httpstepid bigint DEFAULT '0' NOT NULL,\
 itemid bigint DEFAULT '0' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (httpstepitemid)\
);\
CREATE UNIQUE INDEX httpstepitem_httpstepitem_1 on httpstepitem (httpstepid,itemid);\
CREATE TABLE httptestitem (\
 httptestitemid bigint DEFAULT '0' NOT NULL,\
 httptestid bigint DEFAULT '0' NOT NULL,\
 itemid bigint DEFAULT '0' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (httptestitemid)\
);\
CREATE UNIQUE INDEX httptestitem_httptestitem_1 on httptestitem (httptestid,itemid);\
CREATE TABLE nodes (\
 nodeid integer DEFAULT '0' NOT NULL,\
 name varchar(64) DEFAULT '0' NOT NULL,\
 timezone integer DEFAULT '0' NOT NULL,\
 ip varchar(39) DEFAULT '' NOT NULL,\
 port integer DEFAULT '10051' NOT NULL,\
 slave_history integer DEFAULT '30' NOT NULL,\
 slave_trends integer DEFAULT '365' NOT NULL,\
 nodetype integer DEFAULT '0' NOT NULL,\
 masterid integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (nodeid)\
);\
CREATE TABLE node_cksum (\
 nodeid integer DEFAULT '0' NOT NULL,\
 tablename varchar(64) DEFAULT '' NOT NULL,\
 recordid bigint DEFAULT '0' NOT NULL,\
 cksumtype integer DEFAULT '0' NOT NULL,\
 cksum text DEFAULT '' NOT NULL,\
 sync char(128) DEFAULT '' NOT NULL\
);\
CREATE INDEX node_cksum_1 on node_cksum (nodeid,cksumtype,tablename,recordid);\
CREATE TABLE services_times (\
 timeid bigint DEFAULT '0' NOT NULL,\
 serviceid bigint DEFAULT '0' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 ts_from integer DEFAULT '0' NOT NULL,\
 ts_to integer DEFAULT '0' NOT NULL,\
 note varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (timeid)\
);\
CREATE INDEX services_times_times_1 on services_times (serviceid,type,ts_from,ts_to);\
CREATE TABLE alerts (\
 alertid bigint DEFAULT '0' NOT NULL,\
 actionid bigint DEFAULT '0' NOT NULL,\
 eventid bigint DEFAULT '0' NOT NULL,\
 userid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 mediatypeid bigint DEFAULT '0' NOT NULL,\
 sendto varchar(100) DEFAULT '' NOT NULL,\
 subject varchar(255) DEFAULT '' NOT NULL,\
 message blob DEFAULT '' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 retries integer DEFAULT '0' NOT NULL,\
 error varchar(128) DEFAULT '' NOT NULL,\
 nextcheck integer DEFAULT '0' NOT NULL,\
 esc_step integer DEFAULT '0' NOT NULL,\
 alerttype integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (alertid)\
);\
CREATE INDEX alerts_1 on alerts (actionid);\
CREATE INDEX alerts_2 on alerts (clock);\
CREATE INDEX alerts_3 on alerts (eventid);\
CREATE INDEX alerts_4 on alerts (status,retries);\
CREATE INDEX alerts_5 on alerts (mediatypeid);\
CREATE INDEX alerts_6 on alerts (userid);\
CREATE TABLE history (\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 value double(16,4) DEFAULT '0.0000' NOT NULL\
);\
CREATE INDEX history_1 on history (itemid,clock);\
CREATE TABLE history_sync (\
 id integer NOT NULL PRIMARY KEY AUTOINCREMENT,\
 nodeid bigint DEFAULT '0' NOT NULL,\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 value double(16,4) DEFAULT '0.0000' NOT NULL\
);\
CREATE INDEX history_sync_1 on history_sync (nodeid,id);\
CREATE TABLE history_uint (\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 value bigint DEFAULT '0' NOT NULL\
);\
CREATE INDEX history_uint_1 on history_uint (itemid,clock);\
CREATE TABLE history_uint_sync (\
 id integer NOT NULL PRIMARY KEY AUTOINCREMENT,\
 nodeid bigint DEFAULT '0' NOT NULL,\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 value bigint DEFAULT '0' NOT NULL\
);\
CREATE INDEX history_uint_sync_1 on history_uint_sync (nodeid,id);\
CREATE TABLE history_str (\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 value varchar(255) DEFAULT '' NOT NULL\
);\
CREATE INDEX history_str_1 on history_str (itemid,clock);\
CREATE TABLE history_str_sync (\
 id integer NOT NULL PRIMARY KEY AUTOINCREMENT,\
 nodeid bigint DEFAULT '0' NOT NULL,\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 value varchar(255) DEFAULT '' NOT NULL\
);\
CREATE INDEX history_str_sync_1 on history_str_sync (nodeid,id);\
CREATE TABLE history_log (\
 id bigint DEFAULT '0' NOT NULL,\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 timestamp integer DEFAULT '0' NOT NULL,\
 source varchar(64) DEFAULT '' NOT NULL,\
 severity integer DEFAULT '0' NOT NULL,\
 value text DEFAULT '' NOT NULL,\
 logeventid integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (id)\
);\
CREATE INDEX history_log_1 on history_log (itemid,clock);\
CREATE UNIQUE INDEX history_log_2 on history_log (itemid,id);\
CREATE TABLE history_text (\
 id bigint DEFAULT '0' NOT NULL,\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 value text DEFAULT '' NOT NULL,\
 PRIMARY KEY (id)\
);\
CREATE INDEX history_text_1 on history_text (itemid,clock);\
CREATE UNIQUE INDEX history_text_2 on history_text (itemid,id);\
CREATE TABLE proxy_history (\
 id integer NOT NULL PRIMARY KEY AUTOINCREMENT,\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 timestamp integer DEFAULT '0' NOT NULL,\
 source varchar(64) DEFAULT '' NOT NULL,\
 severity integer DEFAULT '0' NOT NULL,\
 value text DEFAULT '' NOT NULL,\
 logeventid integer DEFAULT '0' NOT NULL\
);\
CREATE INDEX proxy_history_1 on proxy_history (clock);\
CREATE TABLE proxy_dhistory (\
 id integer NOT NULL PRIMARY KEY AUTOINCREMENT,\
 clock integer DEFAULT '0' NOT NULL,\
 druleid bigint DEFAULT '0' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 ip varchar(39) DEFAULT '' NOT NULL,\
 port integer DEFAULT '0' NOT NULL,\
 key_ varchar(255) DEFAULT '' NOT NULL,\
 value varchar(255) DEFAULT '' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 dcheckid bigint DEFAULT '0' NOT NULL\
);\
CREATE INDEX proxy_dhistory_1 on proxy_dhistory (clock);\
CREATE TABLE events (\
 eventid bigint DEFAULT '0' NOT NULL,\
 source integer DEFAULT '0' NOT NULL,\
 object integer DEFAULT '0' NOT NULL,\
 objectid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 value integer DEFAULT '0' NOT NULL,\
 acknowledged integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (eventid)\
);\
CREATE INDEX events_1 on events (object,objectid,eventid);\
CREATE INDEX events_2 on events (clock);\
CREATE TABLE trends (\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 num integer DEFAULT '0' NOT NULL,\
 value_min double(16,4) DEFAULT '0.0000' NOT NULL,\
 value_avg double(16,4) DEFAULT '0.0000' NOT NULL,\
 value_max double(16,4) DEFAULT '0.0000' NOT NULL,\
 PRIMARY KEY (itemid,clock)\
);\
CREATE TABLE trends_uint (\
 itemid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 num integer DEFAULT '0' NOT NULL,\
 value_min bigint DEFAULT '0' NOT NULL,\
 value_avg bigint DEFAULT '0' NOT NULL,\
 value_max bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (itemid,clock)\
);\
CREATE TABLE acknowledges (\
 acknowledgeid bigint DEFAULT '0' NOT NULL,\
 userid bigint DEFAULT '0' NOT NULL,\
 eventid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 message varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (acknowledgeid)\
);\
CREATE INDEX acknowledges_1 on acknowledges (userid);\
CREATE INDEX acknowledges_2 on acknowledges (eventid);\
CREATE INDEX acknowledges_3 on acknowledges (clock);\
CREATE TABLE auditlog (\
 auditid bigint DEFAULT '0' NOT NULL,\
 userid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 action integer DEFAULT '0' NOT NULL,\
 resourcetype integer DEFAULT '0' NOT NULL,\
 details varchar(128) DEFAULT '0' NOT NULL,\
 ip varchar(39) DEFAULT '' NOT NULL,\
 resourceid bigint DEFAULT '0' NOT NULL,\
 resourcename varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (auditid)\
);\
CREATE INDEX auditlog_1 on auditlog (userid,clock);\
CREATE INDEX auditlog_2 on auditlog (clock);\
CREATE TABLE auditlog_details (\
 auditdetailid bigint DEFAULT '0' NOT NULL,\
 auditid bigint DEFAULT '0' NOT NULL,\
 table_name varchar(64) DEFAULT '' NOT NULL,\
 field_name varchar(64) DEFAULT '' NOT NULL,\
 oldvalue blob DEFAULT '' NOT NULL,\
 newvalue blob DEFAULT '' NOT NULL,\
 PRIMARY KEY (auditdetailid)\
);\
CREATE INDEX auditlog_details_1 on auditlog_details (auditid);\
CREATE TABLE service_alarms (\
 servicealarmid bigint DEFAULT '0' NOT NULL,\
 serviceid bigint DEFAULT '0' NOT NULL,\
 clock integer DEFAULT '0' NOT NULL,\
 value integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (servicealarmid)\
);\
CREATE INDEX service_alarms_1 on service_alarms (serviceid,clock);\
CREATE INDEX service_alarms_2 on service_alarms (clock);\
CREATE TABLE actions (\
 actionid bigint DEFAULT '0' NOT NULL,\
 name varchar(255) DEFAULT '' NOT NULL,\
 eventsource integer DEFAULT '0' NOT NULL,\
 evaltype integer DEFAULT '0' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 esc_period integer DEFAULT '0' NOT NULL,\
 def_shortdata varchar(255) DEFAULT '' NOT NULL,\
 def_longdata blob DEFAULT '' NOT NULL,\
 recovery_msg integer DEFAULT '0' NOT NULL,\
 r_shortdata varchar(255) DEFAULT '' NOT NULL,\
 r_longdata blob DEFAULT '' NOT NULL,\
 PRIMARY KEY (actionid)\
);\
CREATE INDEX actions_1 on actions (eventsource,status);\
CREATE TABLE operations (\
 operationid bigint DEFAULT '0' NOT NULL,\
 actionid bigint DEFAULT '0' NOT NULL,\
 operationtype integer DEFAULT '0' NOT NULL,\
 object integer DEFAULT '0' NOT NULL,\
 objectid bigint DEFAULT '0' NOT NULL,\
 shortdata varchar(255) DEFAULT '' NOT NULL,\
 longdata blob DEFAULT '' NOT NULL,\
 esc_period integer DEFAULT '0' NOT NULL,\
 esc_step_from integer DEFAULT '0' NOT NULL,\
 esc_step_to integer DEFAULT '0' NOT NULL,\
 default_msg integer DEFAULT '0' NOT NULL,\
 evaltype integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (operationid)\
);\
CREATE INDEX operations_1 on operations (actionid);\
CREATE TABLE opconditions (\
 opconditionid bigint DEFAULT '0' NOT NULL,\
 operationid bigint DEFAULT '0' NOT NULL,\
 conditiontype integer DEFAULT '0' NOT NULL,\
 operator integer DEFAULT '0' NOT NULL,\
 value varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (opconditionid)\
);\
CREATE INDEX opconditions_1 on opconditions (operationid);\
CREATE TABLE opmediatypes (\
 opmediatypeid bigint DEFAULT '0' NOT NULL,\
 operationid bigint DEFAULT '0' NOT NULL,\
 mediatypeid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (opmediatypeid)\
);\
CREATE UNIQUE INDEX opmediatypes_1 on opmediatypes (operationid);\
CREATE TABLE escalations (\
 escalationid bigint DEFAULT '0' NOT NULL,\
 actionid bigint DEFAULT '0' NOT NULL,\
 triggerid bigint DEFAULT '0' NOT NULL,\
 eventid bigint DEFAULT '0' NOT NULL,\
 r_eventid bigint DEFAULT '0' NOT NULL,\
 nextcheck integer DEFAULT '0' NOT NULL,\
 esc_step integer DEFAULT '0' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (escalationid)\
);\
CREATE INDEX escalations_1 on escalations (actionid,triggerid);\
CREATE INDEX escalations_2 on escalations (status,nextcheck);\
CREATE TABLE applications (\
 applicationid bigint DEFAULT '0' NOT NULL,\
 hostid bigint DEFAULT '0' NOT NULL,\
 name varchar(255) DEFAULT '' NOT NULL,\
 templateid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (applicationid)\
);\
CREATE INDEX applications_1 on applications (templateid);\
CREATE UNIQUE INDEX applications_2 on applications (hostid,name);\
CREATE TABLE conditions (\
 conditionid bigint DEFAULT '0' NOT NULL,\
 actionid bigint DEFAULT '0' NOT NULL,\
 conditiontype integer DEFAULT '0' NOT NULL,\
 operator integer DEFAULT '0' NOT NULL,\
 value varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (conditionid)\
);\
CREATE INDEX conditions_1 on conditions (actionid);\
CREATE TABLE config (\
 configid bigint DEFAULT '0' NOT NULL,\
 alert_history integer DEFAULT '0' NOT NULL,\
 event_history integer DEFAULT '0' NOT NULL,\
 refresh_unsupported integer DEFAULT '0' NOT NULL,\
 work_period varchar(100) DEFAULT '1-5,00:00-24:00' NOT NULL,\
 alert_usrgrpid bigint DEFAULT '0' NOT NULL,\
 event_ack_enable integer DEFAULT '1' NOT NULL,\
 event_expire integer DEFAULT '7' NOT NULL,\
 event_show_max integer DEFAULT '100' NOT NULL,\
 default_theme varchar(128) DEFAULT 'default.css' NOT NULL,\
 authentication_type integer DEFAULT '0' NOT NULL,\
 ldap_host varchar(255) DEFAULT '' NOT NULL,\
 ldap_port integer DEFAULT 389 NOT NULL,\
 ldap_base_dn varchar(255) DEFAULT '' NOT NULL,\
 ldap_bind_dn varchar(255) DEFAULT '' NOT NULL,\
 ldap_bind_password varchar(128) DEFAULT '' NOT NULL,\
 ldap_search_attribute varchar(128) DEFAULT '' NOT NULL,\
 dropdown_first_entry integer DEFAULT '1' NOT NULL,\
 dropdown_first_remember integer DEFAULT '1' NOT NULL,\
 discovery_groupid bigint DEFAULT '0' NOT NULL,\
 max_in_table integer DEFAULT '50' NOT NULL,\
 search_limit integer DEFAULT '1000' NOT NULL,\
 PRIMARY KEY (configid)\
);\
CREATE TABLE functions (\
 functionid bigint DEFAULT '0' NOT NULL,\
 itemid bigint DEFAULT '0' NOT NULL,\
 triggerid bigint DEFAULT '0' NOT NULL,\
 lastvalue varchar(255) ,\
 function varchar(12) DEFAULT '' NOT NULL,\
 parameter varchar(255) DEFAULT '0' NOT NULL,\
 PRIMARY KEY (functionid)\
);\
CREATE INDEX functions_1 on functions (triggerid);\
CREATE INDEX functions_2 on functions (itemid,function,parameter);\
CREATE TABLE graphs (\
 graphid bigint DEFAULT '0' NOT NULL,\
 name varchar(128) DEFAULT '' NOT NULL,\
 width integer DEFAULT '0' NOT NULL,\
 height integer DEFAULT '0' NOT NULL,\
 yaxismin double(16,4) DEFAULT '0' NOT NULL,\
 yaxismax double(16,4) DEFAULT '0' NOT NULL,\
 templateid bigint DEFAULT '0' NOT NULL,\
 show_work_period integer DEFAULT '1' NOT NULL,\
 show_triggers integer DEFAULT '1' NOT NULL,\
 graphtype integer DEFAULT '0' NOT NULL,\
 show_legend integer DEFAULT '0' NOT NULL,\
 show_3d integer DEFAULT '0' NOT NULL,\
 percent_left double(16,4) DEFAULT '0' NOT NULL,\
 percent_right double(16,4) DEFAULT '0' NOT NULL,\
 ymin_type integer DEFAULT '0' NOT NULL,\
 ymax_type integer DEFAULT '0' NOT NULL,\
 ymin_itemid bigint DEFAULT '0' NOT NULL,\
 ymax_itemid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (graphid)\
);\
CREATE INDEX graphs_graphs_1 on graphs (name);\
CREATE TABLE graphs_items (\
 gitemid bigint DEFAULT '0' NOT NULL,\
 graphid bigint DEFAULT '0' NOT NULL,\
 itemid bigint DEFAULT '0' NOT NULL,\
 drawtype integer DEFAULT '0' NOT NULL,\
 sortorder integer DEFAULT '0' NOT NULL,\
 color varchar(6) DEFAULT '009600' NOT NULL,\
 yaxisside integer DEFAULT '1' NOT NULL,\
 calc_fnc integer DEFAULT '2' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 periods_cnt integer DEFAULT '5' NOT NULL,\
 PRIMARY KEY (gitemid)\
);\
CREATE INDEX graphs_items_1 on graphs_items (itemid);\
CREATE INDEX graphs_items_2 on graphs_items (graphid);\
CREATE TABLE graph_theme (\
 graphthemeid bigint DEFAULT '0' NOT NULL,\
 description varchar(64) DEFAULT '' NOT NULL,\
 theme varchar(64) DEFAULT '' NOT NULL,\
 backgroundcolor varchar(6) DEFAULT 'F0F0F0' NOT NULL,\
 graphcolor varchar(6) DEFAULT 'FFFFFF' NOT NULL,\
 graphbordercolor varchar(6) DEFAULT '222222' NOT NULL,\
 gridcolor varchar(6) DEFAULT 'CCCCCC' NOT NULL,\
 maingridcolor varchar(6) DEFAULT 'AAAAAA' NOT NULL,\
 gridbordercolor varchar(6) DEFAULT '000000' NOT NULL,\
 textcolor varchar(6) DEFAULT '202020' NOT NULL,\
 highlightcolor varchar(6) DEFAULT 'AA4444' NOT NULL,\
 leftpercentilecolor varchar(6) DEFAULT '11CC11' NOT NULL,\
 rightpercentilecolor varchar(6) DEFAULT 'CC1111' NOT NULL,\
 noneworktimecolor varchar(6) DEFAULT 'CCCCCC' NOT NULL,\
 gridview integer DEFAULT 1 NOT NULL,\
 legendview integer DEFAULT 1 NOT NULL,\
 PRIMARY KEY (graphthemeid)\
);\
CREATE INDEX graph_theme_1 on graph_theme (description);\
CREATE INDEX graph_theme_2 on graph_theme (theme);\
CREATE TABLE groups (\
 groupid bigint DEFAULT '0' NOT NULL,\
 name varchar(64) DEFAULT '' NOT NULL,\
 internal integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (groupid)\
);\
CREATE INDEX groups_1 on groups (name);\
CREATE TABLE help_items (\
 itemtype integer DEFAULT '0' NOT NULL,\
 key_ varchar(255) DEFAULT '' NOT NULL,\
 description varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (itemtype,key_)\
);\
CREATE TABLE hosts (\
 hostid bigint DEFAULT '0' NOT NULL,\
 proxy_hostid bigint DEFAULT '0' NOT NULL,\
 host varchar(64) DEFAULT '' NOT NULL,\
 dns varchar(64) DEFAULT '' NOT NULL,\
 useip integer DEFAULT '1' NOT NULL,\
 ip varchar(39) DEFAULT '127.0.0.1' NOT NULL,\
 port integer DEFAULT '10050' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 disable_until integer DEFAULT '0' NOT NULL,\
 error varchar(128) DEFAULT '' NOT NULL,\
 available integer DEFAULT '0' NOT NULL,\
 errors_from integer DEFAULT '0' NOT NULL,\
 lastaccess integer DEFAULT '0' NOT NULL,\
 inbytes bigint DEFAULT '0' NOT NULL,\
 outbytes bigint DEFAULT '0' NOT NULL,\
 useipmi integer DEFAULT '0' NOT NULL,\
 ipmi_port integer DEFAULT '623' NOT NULL,\
 ipmi_authtype integer DEFAULT '0' NOT NULL,\
 ipmi_privilege integer DEFAULT '2' NOT NULL,\
 ipmi_username varchar(16) DEFAULT '' NOT NULL,\
 ipmi_password varchar(20) DEFAULT '' NOT NULL,\
 ipmi_disable_until integer DEFAULT '0' NOT NULL,\
 ipmi_available integer DEFAULT '0' NOT NULL,\
 snmp_disable_until integer DEFAULT '0' NOT NULL,\
 snmp_available integer DEFAULT '0' NOT NULL,\
 maintenanceid bigint DEFAULT '0' NOT NULL,\
 maintenance_status integer DEFAULT '0' NOT NULL,\
 maintenance_type integer DEFAULT '0' NOT NULL,\
 maintenance_from integer DEFAULT '0' NOT NULL,\
 ipmi_ip varchar(64) DEFAULT '127.0.0.1' NOT NULL,\
 ipmi_errors_from integer DEFAULT '0' NOT NULL,\
 snmp_errors_from integer DEFAULT '0' NOT NULL,\
 ipmi_error varchar(128) DEFAULT '' NOT NULL,\
 snmp_error varchar(128) DEFAULT '' NOT NULL,\
 PRIMARY KEY (hostid)\
);\
CREATE INDEX hosts_1 on hosts (host);\
CREATE INDEX hosts_2 on hosts (status);\
CREATE INDEX hosts_3 on hosts (proxy_hostid);\
CREATE TABLE globalmacro (\
 globalmacroid bigint DEFAULT '0' NOT NULL,\
 macro varchar(64) DEFAULT '' NOT NULL,\
 value varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (globalmacroid)\
);\
CREATE INDEX globalmacro_1 on globalmacro (macro);\
CREATE TABLE hostmacro (\
 hostmacroid bigint DEFAULT '0' NOT NULL,\
 hostid bigint DEFAULT '0' NOT NULL,\
 macro varchar(64) DEFAULT '' NOT NULL,\
 value varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (hostmacroid)\
);\
CREATE INDEX hostmacro_1 on hostmacro (hostid,macro);\
CREATE TABLE hosts_groups (\
 hostgroupid bigint DEFAULT '0' NOT NULL,\
 hostid bigint DEFAULT '0' NOT NULL,\
 groupid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (hostgroupid)\
);\
CREATE INDEX hosts_groups_1 on hosts_groups (hostid,groupid);\
CREATE INDEX hosts_groups_2 on hosts_groups (groupid);\
CREATE TABLE hosts_profiles (\
 hostid bigint DEFAULT '0' NOT NULL,\
 devicetype varchar(64) DEFAULT '' NOT NULL,\
 name varchar(64) DEFAULT '' NOT NULL,\
 os varchar(64) DEFAULT '' NOT NULL,\
 serialno varchar(64) DEFAULT '' NOT NULL,\
 tag varchar(64) DEFAULT '' NOT NULL,\
 macaddress varchar(64) DEFAULT '' NOT NULL,\
 hardware blob DEFAULT '' NOT NULL,\
 software blob DEFAULT '' NOT NULL,\
 contact blob DEFAULT '' NOT NULL,\
 location blob DEFAULT '' NOT NULL,\
 notes blob DEFAULT '' NOT NULL,\
 PRIMARY KEY (hostid)\
);\
CREATE TABLE hosts_profiles_ext (\
 hostid bigint DEFAULT '0' NOT NULL,\
 device_alias varchar(64) DEFAULT '' NOT NULL,\
 device_type varchar(64) DEFAULT '' NOT NULL,\
 device_chassis varchar(64) DEFAULT '' NOT NULL,\
 device_os varchar(64) DEFAULT '' NOT NULL,\
 device_os_short varchar(64) DEFAULT '' NOT NULL,\
 device_hw_arch varchar(32) DEFAULT '' NOT NULL,\
 device_serial varchar(64) DEFAULT '' NOT NULL,\
 device_model varchar(64) DEFAULT '' NOT NULL,\
 device_tag varchar(64) DEFAULT '' NOT NULL,\
 device_vendor varchar(64) DEFAULT '' NOT NULL,\
 device_contract varchar(64) DEFAULT '' NOT NULL,\
 device_who varchar(64) DEFAULT '' NOT NULL,\
 device_status varchar(64) DEFAULT '' NOT NULL,\
 device_app_01 varchar(64) DEFAULT '' NOT NULL,\
 device_app_02 varchar(64) DEFAULT '' NOT NULL,\
 device_app_03 varchar(64) DEFAULT '' NOT NULL,\
 device_app_04 varchar(64) DEFAULT '' NOT NULL,\
 device_app_05 varchar(64) DEFAULT '' NOT NULL,\
 device_url_1 varchar(255) DEFAULT '' NOT NULL,\
 device_url_2 varchar(255) DEFAULT '' NOT NULL,\
 device_url_3 varchar(255) DEFAULT '' NOT NULL,\
 device_networks blob DEFAULT '' NOT NULL,\
 device_notes blob DEFAULT '' NOT NULL,\
 device_hardware blob DEFAULT '' NOT NULL,\
 device_software blob DEFAULT '' NOT NULL,\
 ip_subnet_mask varchar(39) DEFAULT '' NOT NULL,\
 ip_router varchar(39) DEFAULT '' NOT NULL,\
 ip_macaddress varchar(64) DEFAULT '' NOT NULL,\
 oob_ip varchar(39) DEFAULT '' NOT NULL,\
 oob_subnet_mask varchar(39) DEFAULT '' NOT NULL,\
 oob_router varchar(39) DEFAULT '' NOT NULL,\
 date_hw_buy varchar(64) DEFAULT '' NOT NULL,\
 date_hw_install varchar(64) DEFAULT '' NOT NULL,\
 date_hw_expiry varchar(64) DEFAULT '' NOT NULL,\
 date_hw_decomm varchar(64) DEFAULT '' NOT NULL,\
 site_street_1 varchar(128) DEFAULT '' NOT NULL,\
 site_street_2 varchar(128) DEFAULT '' NOT NULL,\
 site_street_3 varchar(128) DEFAULT '' NOT NULL,\
 site_city varchar(128) DEFAULT '' NOT NULL,\
 site_state varchar(64) DEFAULT '' NOT NULL,\
 site_country varchar(64) DEFAULT '' NOT NULL,\
 site_zip varchar(64) DEFAULT '' NOT NULL,\
 site_rack varchar(128) DEFAULT '' NOT NULL,\
 site_notes blob DEFAULT '' NOT NULL,\
 poc_1_name varchar(128) DEFAULT '' NOT NULL,\
 poc_1_email varchar(128) DEFAULT '' NOT NULL,\
 poc_1_phone_1 varchar(64) DEFAULT '' NOT NULL,\
 poc_1_phone_2 varchar(64) DEFAULT '' NOT NULL,\
 poc_1_cell varchar(64) DEFAULT '' NOT NULL,\
 poc_1_screen varchar(64) DEFAULT '' NOT NULL,\
 poc_1_notes blob DEFAULT '' NOT NULL,\
 poc_2_name varchar(128) DEFAULT '' NOT NULL,\
 poc_2_email varchar(128) DEFAULT '' NOT NULL,\
 poc_2_phone_1 varchar(64) DEFAULT '' NOT NULL,\
 poc_2_phone_2 varchar(64) DEFAULT '' NOT NULL,\
 poc_2_cell varchar(64) DEFAULT '' NOT NULL,\
 poc_2_screen varchar(64) DEFAULT '' NOT NULL,\
 poc_2_notes blob DEFAULT '' NOT NULL,\
 PRIMARY KEY (hostid)\
);\
CREATE TABLE hosts_templates (\
 hosttemplateid bigint DEFAULT '0' NOT NULL,\
 hostid bigint DEFAULT '0' NOT NULL,\
 templateid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (hosttemplateid)\
);\
CREATE UNIQUE INDEX hosts_templates_1 on hosts_templates (hostid,templateid);\
CREATE INDEX hosts_templates_2 on hosts_templates (templateid);\
CREATE TABLE housekeeper (\
 housekeeperid bigint DEFAULT '0' NOT NULL,\
 tablename varchar(64) DEFAULT '' NOT NULL,\
 field varchar(64) DEFAULT '' NOT NULL,\
 value bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (housekeeperid)\
);\
CREATE TABLE images (\
 imageid bigint DEFAULT '0' NOT NULL,\
 imagetype integer DEFAULT '0' NOT NULL,\
 name varchar(64) DEFAULT '0' NOT NULL,\
 image longblob DEFAULT '' NOT NULL,\
 PRIMARY KEY (imageid)\
);\
CREATE INDEX images_1 on images (imagetype,name);\
CREATE TABLE items (\
 itemid bigint DEFAULT '0' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 snmp_community varchar(64) DEFAULT '' NOT NULL,\
 snmp_oid varchar(255) DEFAULT '' NOT NULL,\
 snmp_port integer DEFAULT '161' NOT NULL,\
 hostid bigint DEFAULT '0' NOT NULL,\
 description varchar(255) DEFAULT '' NOT NULL,\
 key_ varchar(255) DEFAULT '' NOT NULL,\
 delay integer DEFAULT '0' NOT NULL,\
 history integer DEFAULT '90' NOT NULL,\
 trends integer DEFAULT '365' NOT NULL,\
 lastvalue varchar(255) NULL,\
 lastclock integer NULL,\
 prevvalue varchar(255) NULL,\
 status integer DEFAULT '0' NOT NULL,\
 value_type integer DEFAULT '0' NOT NULL,\
 trapper_hosts varchar(255) DEFAULT '' NOT NULL,\
 units varchar(10) DEFAULT '' NOT NULL,\
 multiplier integer DEFAULT '0' NOT NULL,\
 delta integer DEFAULT '0' NOT NULL,\
 prevorgvalue varchar(255) NULL,\
 snmpv3_securityname varchar(64) DEFAULT '' NOT NULL,\
 snmpv3_securitylevel integer DEFAULT '0' NOT NULL,\
 snmpv3_authpassphrase varchar(64) DEFAULT '' NOT NULL,\
 snmpv3_privpassphrase varchar(64) DEFAULT '' NOT NULL,\
 formula varchar(255) DEFAULT '1' NOT NULL,\
 error varchar(128) DEFAULT '' NOT NULL,\
 lastlogsize integer DEFAULT '0' NOT NULL,\
 logtimefmt varchar(64) DEFAULT '' NOT NULL,\
 templateid bigint DEFAULT '0' NOT NULL,\
 valuemapid bigint DEFAULT '0' NOT NULL,\
 delay_flex varchar(255) DEFAULT '' NOT NULL,\
 params text DEFAULT '' NOT NULL,\
 ipmi_sensor varchar(128) DEFAULT '' NOT NULL,\
 data_type integer DEFAULT '0' NOT NULL,\
 authtype integer DEFAULT '0' NOT NULL,\
 username varchar(64) DEFAULT '' NOT NULL,\
 password varchar(64) DEFAULT '' NOT NULL,\
 publickey varchar(64) DEFAULT '' NOT NULL,\
 privatekey varchar(64) DEFAULT '' NOT NULL,\
 mtime integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (itemid)\
);\
CREATE UNIQUE INDEX items_1 on items (hostid,key_);\
CREATE INDEX items_3 on items (status);\
CREATE INDEX items_4 on items (templateid);\
CREATE TABLE items_applications (\
 itemappid bigint DEFAULT '0' NOT NULL,\
 applicationid bigint DEFAULT '0' NOT NULL,\
 itemid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (itemappid)\
);\
CREATE INDEX items_applications_1 on items_applications (applicationid,itemid);\
CREATE INDEX items_applications_2 on items_applications (itemid);\
CREATE TABLE mappings (\
 mappingid bigint DEFAULT '0' NOT NULL,\
 valuemapid bigint DEFAULT '0' NOT NULL,\
 value varchar(64) DEFAULT '' NOT NULL,\
 newvalue varchar(64) DEFAULT '' NOT NULL,\
 PRIMARY KEY (mappingid)\
);\
CREATE INDEX mappings_1 on mappings (valuemapid);\
CREATE TABLE media (\
 mediaid bigint DEFAULT '0' NOT NULL,\
 userid bigint DEFAULT '0' NOT NULL,\
 mediatypeid bigint DEFAULT '0' NOT NULL,\
 sendto varchar(100) DEFAULT '' NOT NULL,\
 active integer DEFAULT '0' NOT NULL,\
 severity integer DEFAULT '63' NOT NULL,\
 period varchar(100) DEFAULT '1-7,00:00-23:59' NOT NULL,\
 PRIMARY KEY (mediaid)\
);\
CREATE INDEX media_1 on media (userid);\
CREATE INDEX media_2 on media (mediatypeid);\
CREATE TABLE media_type (\
 mediatypeid bigint DEFAULT '0' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 description varchar(100) DEFAULT '' NOT NULL,\
 smtp_server varchar(255) DEFAULT '' NOT NULL,\
 smtp_helo varchar(255) DEFAULT '' NOT NULL,\
 smtp_email varchar(255) DEFAULT '' NOT NULL,\
 exec_path varchar(255) DEFAULT '' NOT NULL,\
 gsm_modem varchar(255) DEFAULT '' NOT NULL,\
 username varchar(255) DEFAULT '' NOT NULL,\
 passwd varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (mediatypeid)\
);\
CREATE TABLE profiles (\
 profileid bigint DEFAULT '0' NOT NULL,\
 userid bigint DEFAULT '0' NOT NULL,\
 idx varchar(96) DEFAULT '' NOT NULL,\
 idx2 bigint DEFAULT '0' NOT NULL,\
 value_id bigint DEFAULT '0' NOT NULL,\
 value_int integer DEFAULT '0' NOT NULL,\
 value_str varchar(255) DEFAULT '' NOT NULL,\
 source varchar(96) DEFAULT '' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (profileid)\
);\
CREATE INDEX profiles_1 on profiles (userid,idx,idx2);\
CREATE INDEX profiles_2 on profiles (userid,profileid);\
CREATE TABLE rights (\
 rightid bigint DEFAULT '0' NOT NULL,\
 groupid bigint DEFAULT '0' NOT NULL,\
 permission integer DEFAULT '0' NOT NULL,\
 id bigint ,\
 PRIMARY KEY (rightid)\
);\
CREATE INDEX rights_1 on rights (groupid);\
CREATE INDEX rights_2 on rights (id);\
CREATE TABLE scripts (\
 scriptid bigint DEFAULT '0' NOT NULL,\
 name varchar(255) DEFAULT '' NOT NULL,\
 command varchar(255) DEFAULT '' NOT NULL,\
 host_access integer DEFAULT '2' NOT NULL,\
 usrgrpid bigint DEFAULT '0' NOT NULL,\
 groupid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (scriptid)\
);\
CREATE TABLE screens (\
 screenid bigint DEFAULT '0' NOT NULL,\
 name varchar(255) DEFAULT 'Screen' NOT NULL,\
 hsize integer DEFAULT '1' NOT NULL,\
 vsize integer DEFAULT '1' NOT NULL,\
 PRIMARY KEY (screenid)\
);\
CREATE TABLE screens_items (\
 screenitemid bigint DEFAULT '0' NOT NULL,\
 screenid bigint DEFAULT '0' NOT NULL,\
 resourcetype integer DEFAULT '0' NOT NULL,\
 resourceid bigint DEFAULT '0' NOT NULL,\
 width integer DEFAULT '320' NOT NULL,\
 height integer DEFAULT '200' NOT NULL,\
 x integer DEFAULT '0' NOT NULL,\
 y integer DEFAULT '0' NOT NULL,\
 colspan integer DEFAULT '0' NOT NULL,\
 rowspan integer DEFAULT '0' NOT NULL,\
 elements integer DEFAULT '25' NOT NULL,\
 valign integer DEFAULT '0' NOT NULL,\
 halign integer DEFAULT '0' NOT NULL,\
 style integer DEFAULT '0' NOT NULL,\
 url varchar(255) DEFAULT '' NOT NULL,\
 dynamic integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (screenitemid)\
);\
CREATE TABLE services (\
 serviceid bigint DEFAULT '0' NOT NULL,\
 name varchar(128) DEFAULT '' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 algorithm integer DEFAULT '0' NOT NULL,\
 triggerid bigint ,\
 showsla integer DEFAULT '0' NOT NULL,\
 goodsla double(16,4) DEFAULT '99.9' NOT NULL,\
 sortorder integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (serviceid)\
);\
CREATE INDEX services_1 on services (triggerid);\
CREATE TABLE services_links (\
 linkid bigint DEFAULT '0' NOT NULL,\
 serviceupid bigint DEFAULT '0' NOT NULL,\
 servicedownid bigint DEFAULT '0' NOT NULL,\
 soft integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (linkid)\
);\
CREATE INDEX services_links_links_1 on services_links (servicedownid);\
CREATE UNIQUE INDEX services_links_links_2 on services_links (serviceupid,servicedownid);\
CREATE TABLE sessions (\
 sessionid varchar(32) DEFAULT '' NOT NULL,\
 userid bigint DEFAULT '0' NOT NULL,\
 lastaccess integer DEFAULT '0' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (sessionid)\
);\
CREATE INDEX sessions_1 on sessions (userid, status);\
CREATE TABLE sysmaps_links (\
 linkid bigint DEFAULT '0' NOT NULL,\
 sysmapid bigint DEFAULT '0' NOT NULL,\
 selementid1 bigint DEFAULT '0' NOT NULL,\
 selementid2 bigint DEFAULT '0' NOT NULL,\
 drawtype integer DEFAULT '0' NOT NULL,\
 color varchar(6) DEFAULT '000000' NOT NULL,\
 label varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (linkid)\
);\
CREATE TABLE sysmaps_link_triggers (\
 linktriggerid bigint DEFAULT '0' NOT NULL,\
 linkid bigint DEFAULT '0' NOT NULL,\
 triggerid bigint DEFAULT '0' NOT NULL,\
 drawtype integer DEFAULT '0' NOT NULL,\
 color varchar(6) DEFAULT '000000' NOT NULL,\
 PRIMARY KEY (linktriggerid)\
);\
CREATE UNIQUE INDEX sysmaps_link_triggers_1 on sysmaps_link_triggers (linkid,triggerid);\
CREATE TABLE sysmaps_elements (\
 selementid bigint DEFAULT '0' NOT NULL,\
 sysmapid bigint DEFAULT '0' NOT NULL,\
 elementid bigint DEFAULT '0' NOT NULL,\
 elementtype integer DEFAULT '0' NOT NULL,\
 iconid_off bigint DEFAULT '0' NOT NULL,\
 iconid_on bigint DEFAULT '0' NOT NULL,\
 iconid_unknown bigint DEFAULT '0' NOT NULL,\
 label varchar(255) DEFAULT '' NOT NULL,\
 label_location integer NULL,\
 x integer DEFAULT '0' NOT NULL,\
 y integer DEFAULT '0' NOT NULL,\
 url varchar(255) DEFAULT '' NOT NULL,\
 iconid_disabled bigint DEFAULT '0' NOT NULL,\
 iconid_maintenance bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (selementid)\
);\
CREATE TABLE sysmaps (\
 sysmapid bigint DEFAULT '0' NOT NULL,\
 name varchar(128) DEFAULT '' NOT NULL,\
 width integer DEFAULT '0' NOT NULL,\
 height integer DEFAULT '0' NOT NULL,\
 backgroundid bigint DEFAULT '0' NOT NULL,\
 label_type integer DEFAULT '0' NOT NULL,\
 label_location integer DEFAULT '0' NOT NULL,\
 highlight integer DEFAULT '1' NOT NULL,\
 PRIMARY KEY (sysmapid)\
);\
CREATE INDEX sysmaps_1 on sysmaps (name);\
CREATE TABLE triggers (\
 triggerid bigint DEFAULT '0' NOT NULL,\
 expression varchar(255) DEFAULT '' NOT NULL,\
 description varchar(255) DEFAULT '' NOT NULL,\
 url varchar(255) DEFAULT '' NOT NULL,\
 status integer DEFAULT '0' NOT NULL,\
 value integer DEFAULT '0' NOT NULL,\
 priority integer DEFAULT '0' NOT NULL,\
 lastchange integer DEFAULT '0' NOT NULL,\
 dep_level integer DEFAULT '0' NOT NULL,\
 comments blob DEFAULT '' NOT NULL,\
 error varchar(128) DEFAULT '' NOT NULL,\
 templateid bigint DEFAULT '0' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (triggerid)\
);\
CREATE INDEX triggers_1 on triggers (status);\
CREATE INDEX triggers_2 on triggers (value);\
CREATE TABLE trigger_depends (\
 triggerdepid bigint DEFAULT '0' NOT NULL,\
 triggerid_down bigint DEFAULT '0' NOT NULL,\
 triggerid_up bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (triggerdepid)\
);\
CREATE INDEX trigger_depends_1 on trigger_depends (triggerid_down,triggerid_up);\
CREATE INDEX trigger_depends_2 on trigger_depends (triggerid_up);\
CREATE TABLE users (\
 userid bigint DEFAULT '0' NOT NULL,\
 alias varchar(100) DEFAULT '' NOT NULL,\
 name varchar(100) DEFAULT '' NOT NULL,\
 surname varchar(100) DEFAULT '' NOT NULL,\
 passwd char(32) DEFAULT '' NOT NULL,\
 url varchar(255) DEFAULT '' NOT NULL,\
 autologin integer DEFAULT '0' NOT NULL,\
 autologout integer DEFAULT '900' NOT NULL,\
 lang varchar(5) DEFAULT 'en_gb' NOT NULL,\
 refresh integer DEFAULT '30' NOT NULL,\
 type integer DEFAULT '0' NOT NULL,\
 theme varchar(128) DEFAULT 'default.css' NOT NULL,\
 attempt_failed integer DEFAULT 0 NOT NULL,\
 attempt_ip varchar(39) DEFAULT '' NOT NULL,\
 attempt_clock integer DEFAULT 0 NOT NULL,\
 rows_per_page integer DEFAULT 50 NOT NULL,\
 PRIMARY KEY (userid)\
);\
CREATE INDEX users_1 on users (alias);\
CREATE TABLE usrgrp (\
 usrgrpid bigint DEFAULT '0' NOT NULL,\
 name varchar(64) DEFAULT '' NOT NULL,\
 gui_access integer DEFAULT '0' NOT NULL,\
 users_status integer DEFAULT '0' NOT NULL,\
 api_access integer DEFAULT '0' NOT NULL,\
 debug_mode integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (usrgrpid)\
);\
CREATE INDEX usrgrp_1 on usrgrp (name);\
CREATE TABLE users_groups (\
 id bigint DEFAULT '0' NOT NULL,\
 usrgrpid bigint DEFAULT '0' NOT NULL,\
 userid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (id)\
);\
CREATE INDEX users_groups_1 on users_groups (usrgrpid,userid);\
CREATE TABLE valuemaps (\
 valuemapid bigint DEFAULT '0' NOT NULL,\
 name varchar(64) DEFAULT '' NOT NULL,\
 PRIMARY KEY (valuemapid)\
);\
CREATE INDEX valuemaps_1 on valuemaps (name);\
CREATE TABLE maintenances (\
 maintenanceid bigint DEFAULT '0' NOT NULL,\
 name varchar(128) DEFAULT '' NOT NULL,\
 maintenance_type integer DEFAULT '0' NOT NULL,\
 description blob DEFAULT '' NOT NULL,\
 active_since integer DEFAULT '0' NOT NULL,\
 active_till integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (maintenanceid)\
);\
CREATE INDEX maintenances_1 on maintenances (active_since,active_till);\
CREATE TABLE maintenances_hosts (\
 maintenance_hostid bigint DEFAULT '0' NOT NULL,\
 maintenanceid bigint DEFAULT '0' NOT NULL,\
 hostid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (maintenance_hostid)\
);\
CREATE INDEX maintenances_hosts_1 on maintenances_hosts (maintenanceid,hostid);\
CREATE TABLE maintenances_groups (\
 maintenance_groupid bigint DEFAULT '0' NOT NULL,\
 maintenanceid bigint DEFAULT '0' NOT NULL,\
 groupid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (maintenance_groupid)\
);\
CREATE INDEX maintenances_groups_1 on maintenances_groups (maintenanceid,groupid);\
CREATE TABLE maintenances_windows (\
 maintenance_timeperiodid bigint DEFAULT '0' NOT NULL,\
 maintenanceid bigint DEFAULT '0' NOT NULL,\
 timeperiodid bigint DEFAULT '0' NOT NULL,\
 PRIMARY KEY (maintenance_timeperiodid)\
);\
CREATE INDEX maintenances_windows_1 on maintenances_windows (maintenanceid,timeperiodid);\
CREATE TABLE timeperiods (\
 timeperiodid bigint DEFAULT '0' NOT NULL,\
 timeperiod_type integer DEFAULT '0' NOT NULL,\
 every integer DEFAULT '0' NOT NULL,\
 month integer DEFAULT '0' NOT NULL,\
 dayofweek integer DEFAULT '0' NOT NULL,\
 day integer DEFAULT '0' NOT NULL,\
 start_time integer DEFAULT '0' NOT NULL,\
 period integer DEFAULT '0' NOT NULL,\
 start_date integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (timeperiodid)\
);\
CREATE TABLE regexps (\
 regexpid bigint DEFAULT '0' NOT NULL,\
 name varchar(128) DEFAULT '' NOT NULL,\
 test_string blob DEFAULT '' NOT NULL,\
 PRIMARY KEY (regexpid)\
);\
CREATE INDEX regexps_1 on regexps (name);\
CREATE TABLE user_history (\
 userhistoryid bigint DEFAULT '0' NOT NULL,\
 userid bigint DEFAULT '0' NOT NULL,\
 title1 varchar(255) DEFAULT '' NOT NULL,\
 url1 varchar(255) DEFAULT '' NOT NULL,\
 title2 varchar(255) DEFAULT '' NOT NULL,\
 url2 varchar(255) DEFAULT '' NOT NULL,\
 title3 varchar(255) DEFAULT '' NOT NULL,\
 url3 varchar(255) DEFAULT '' NOT NULL,\
 title4 varchar(255) DEFAULT '' NOT NULL,\
 url4 varchar(255) DEFAULT '' NOT NULL,\
 title5 varchar(255) DEFAULT '' NOT NULL,\
 url5 varchar(255) DEFAULT '' NOT NULL,\
 PRIMARY KEY (userhistoryid)\
);\
CREATE UNIQUE INDEX user_history_1 on user_history (userid);\
CREATE TABLE expressions (\
 expressionid bigint DEFAULT '0' NOT NULL,\
 regexpid bigint DEFAULT '0' NOT NULL,\
 expression varchar(255) DEFAULT '' NOT NULL,\
 expression_type integer DEFAULT '0' NOT NULL,\
 exp_delimiter varchar(1) DEFAULT '' NOT NULL,\
 case_sensitive integer DEFAULT '0' NOT NULL,\
 PRIMARY KEY (expressionid)\
);\
CREATE INDEX expressions_1 on expressions (regexpid);\
CREATE TABLE autoreg_host (\
 autoreg_hostid bigint DEFAULT '0' NOT NULL,\
 proxy_hostid bigint DEFAULT '0' NOT NULL,\
 host varchar(64) DEFAULT '' NOT NULL,\
 PRIMARY KEY (autoreg_hostid)\
);\
CREATE INDEX autoreg_host_1 on autoreg_host (proxy_hostid,host);\
CREATE TABLE proxy_autoreg_host (\
 id integer NOT NULL PRIMARY KEY AUTOINCREMENT,\
 clock integer DEFAULT '0' NOT NULL,\
 host varchar(64) DEFAULT '' NOT NULL\
);\
CREATE INDEX proxy_autoreg_host_1 on proxy_autoreg_host (clock);\
COMMIT;\
"};
#endif /* HAVE_SQLITE3 */

