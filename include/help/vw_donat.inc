stock donat_OnPlayerPickUp(playerid, pickupid)
{
	if(pickupid == PickupID[16] &&
		IsPlayerInRangeOfPoint(playerid, 2.1, Pickups[pickupid][p_x],Pickups[pickupid][p_y],Pickups[pickupid][p_z]) )
	{
		//if( !strcmp(php_host, "vw-rp.net", true) )
		Donat(playerid);
		//return 1;
	}
}

stock Donat(playerid)
{
	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
#if defined vw_sql//#endif
	new ToBase[57+24]; new Field[34];
	format(ToBase, sizeof(ToBase), "SELECT `Gold` FROM `players` WHERE `Name`='%s' AND `Gold`>0", PlayerName(playerid));

/*
	mysql_query(ToBase); mysql_store_result();
	if(mysql_num_rows() > 0 && mysql_retrieve_row())
	{
		mysql_fetch_field_row(Field, "Gold"); PlayerInfo[playerid][pGold] = floatstr(Field);//strval(Field);
	}
	else { PlayerInfo[playerid][pGold] = 0; SendClientMessage(playerid, COLOR_GREY, "   � ��� ���� ������ �� ����� !"); }
	mysql_free_result();
*/
	new DBResult:db_result = db_query(db_VW, ToBase);
	if(db_num_rows(db_result))
	{
		db_get_field_assoc(db_result, "Gold", Field, sizeof(Field) ); PlayerInfo[playerid][pGold] = floatstr(Field);//strval(Field);
	}
	else { PlayerInfo[playerid][pGold] = 0; SendClientMessage(playerid, COLOR_GREY, "   � ��� ���� ������ �� ����� !"); }
	db_free_result(db_result);

#endif
	new listitems[1035];
	strcat(listitems, "{FFFFFF}1\t{00FF00}��� ���������.\n");//0
	strcat(listitems, "{FFFFFF}2\t{00FF00}������� ������� ������. ����: 1 ������� = 1200$\n");//1
	strcat(listitems, "{FFFFFF}3\t{00FF00}������ ����� (��������������). ���������: 50 �������\n");
	strcat(listitems, "{FFFFFF}4\t{00FF00}�������� ������. ���������: 50 �������\n");
	strcat(listitems, "{FFFFFF}5\t{00FF00}�������� ������ ������������. ���������: 50 �������\n");
	strcat(listitems, "{FFFFFF}6\t{00FF00}������� VIP �������. ��������� ������ �� 30 ����: 300 �������\n");
	//strcat(listitems, "{FFFFFF}\n7\t{00FF00}�������������� ������ = 80 ������");
	/*strcat(listitems, "{FFFFFF}\n8\t{00FF00}������� ����� ������");
	strcat(listitems, "{FFFFFF}\n9\t{00FF00}������ �� ������");
	strcat(listitems, "{FFFFFF}\n10\t{00FF00}������ �� �������");
	strcat(listitems, "{FFFFFF}\n11\t{00FF00}������ �� �����");
	strcat(listitems, "{FFFFFF}\n12\t{00FF00}������ �� ���������� � ����");
	strcat(listitems, "{FFFFFF}\n13\t{00FF00}������ �� IRC-����");
	strcat(listitems, "{FFFFFF}\n14\t{00FF00}������������ ������� ��������");
	strcat(listitems, "{FFFFFF}\n15\t{00FF00}����� ��������");//13*/
	//strcat(listitems, "{FFFFFF}4\t{00FF00}������ �� �������. ��������� �������: 100 ������\n");
	new caption[70];
	format(caption, sizeof(caption), "*** ����� *** �������� %.1f �������", PlayerInfo[playerid][pGold]);

	if(strlen(listitems) > sizeof(listitems))
	{
		PlayerInfo[playerid][pGold] = 0;
		//��������������
		format(strings, sizeof(strings), "Error: *** ����� *** %s[%d], strlen(listitems): %d, sizeof(listitems): %d",
			PlayerName(playerid), playerid, strlen(listitems), sizeof(listitems));
		Log(ERROR, strings);
		return 1;
	}
	if(strlen(listitems) <= 0)
	{
		PlayerInfo[playerid][pGold] = 0;
		SendClientMessage(playerid, COLOR_GREY, "   ����� ����");//COLOR_BLUEGREY
		return 1;
	}
	MenuOperation[playerid] = 0;
	ShowPlayerDialogEx(playerid, GOLD_DIALOG, DIALOG_STYLE_LIST, caption, listitems, "OK", "Cancel");
	return 1;
}

stock VIPHelp(playerid)
{
	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
	
#if defined vw_sql//#endif
	new ToBase[57+24]; new Field[34];
	format(ToBase, sizeof(ToBase), "SELECT `Gold` FROM `players` WHERE `Name`='%s' AND `Gold`>0 LIMIT 1", PlayerName(playerid));
	/*mysql_query(ToBase); mysql_store_result();
	if(mysql_num_rows() > 0 && mysql_retrieve_row())
	{
		//mysql_fetch_field_row(Field, "Gold"); PlayerInfo[playerid][pGold] = strval(Field);
		mysql_fetch_field_row(Field, "Gold"); PlayerInfo[playerid][pGold] = floatstr(Field);
	}
	else { PlayerInfo[playerid][pGold] = 0; SendClientMessage(playerid, COLOR_GREY, "   � ��� ���� ������ �� ����� !"); }
	mysql_free_result();*/
	
	new DBResult:db_result = db_query(db_VW, ToBase);
	if(db_num_rows(db_result))
	{
		db_get_field_assoc(db_result, "Gold", Field, sizeof(Field) ); PlayerInfo[playerid][pGold] = floatstr(Field);//strval(Field);
	}
	else { PlayerInfo[playerid][pGold] = 0; SendClientMessage(playerid, COLOR_GREY, "   � ��� ���� ������ �� ����� !"); }
	db_free_result(db_result);
#endif

	new dlgitem[1484+113+10];
	strcat(dlgitem, "\n1. �� ��� ���������� � ����� �������� �� ������������, ����� ����������� ��� ���");
	strcat(dlgitem, "\n2. �� ������ � �������������� �� �������� ���. ������");
	strcat(dlgitem, "\n3. ��������� ������ � 100% ��������");
	strcat(dlgitem, "\n4. ����� ����� ��������� � ������ ��� ���������");
	strcat(dlgitem, "\n5. �� ��� �� ����� �������� ����, � ����� �� �� ����� � ������ �������");
	strcat(dlgitem, "\n6. ����� � �������� � ������� �������� ��������");
	strcat(dlgitem, "\n7. +0.2% �� ������, ���� �������� ���� +0.4% �� ������, ���� �� �������� ���� +0.2% �� ������, \n���� �� � ����� +0.3% �� ������");
	strcat(dlgitem, "\n8. �� �������� �������� �������������, \n�.�. ������ �� ����� ������������ � ��� �� ����� ����������� �� �������");
	strcat(dlgitem, "\n9. ����� ����� ����� ��� FIGHT_STYLE_KNEEHEAD (������)");
	strcat(dlgitem, "\n10. ����� ����� ����������� ��� ����� ������ �� ��������, \n�� ��� ���� ����� ���������� ��������");
	strcat(dlgitem, "\n11. ���� ����������� ���������/�������� ������� (/togphone)");
	strcat(dlgitem, "\n12. ���� ����������� �������� ������ ���������������(������) (/admins).");
	strcat(dlgitem, "\n13. ���� ����������� ����������� �� �����������");
	//strcat(dlgitem, "\n14. ������ ban'a/warn'a ������������ ������������� ����� ��������� VIP");
	strcat(dlgitem, "\n15. ��� ���������� �������� � ��� ������ �� �������� ����������");
	//strcat(dlgitem, "\n16. �������� ������� /changeorigin");
	strcat(dlgitem, "\n16. �������� ������� /showtag");
	strcat(dlgitem, "\n17. ��-�� �������� ���-�� ��������� � ���������� �� ���������� �� �������");
	strcat(dlgitem, "\n18. ��-�� ������� ������� �� ���������� �� �������");
	strcat(dlgitem, "\n19. � ��������� ��������� �� ������");
	strcat(dlgitem, "\n20. �� � ��� �� ���������, �.�. ��������� ������������ �� ����");
	//strcat(dlgitem, "\n21. �� ��������� ���������� �� ������� ������������");
	strcat(dlgitem, "\n21. �� ������� � ����� ����");
	strcat(dlgitem, "\n22. ����� ��������� ����� � ����� �����");

	format(dlgitem, sizeof(dlgitem), "%s\n\n��������� ������ �� 30 ����: 300 �������.\
\n�������� %.1f �������.\
\n�� �������� ������ VIP ������ �� 30 ����?", dlgitem, PlayerInfo[playerid][pGold]);
	MenuOperation[playerid] = 5;
	new caption[] = "������� VIP �������";
	ShowPlayerDialogEx(playerid, GOLD_DIALOG, DIALOG_STYLE_MSGBOX, caption, dlgitem, "��", "���");
}

stock donat_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	#pragma unused inputtext
	if(dialogid != GOLD_DIALOG) return 1;
	if(!response) { DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0; MenuOperation[playerid] = 0; return 1; }
	if(MenuOperation[playerid] == 0)
	{
		new dlgitem[969];//64+58+36+45+56+44+37+44+42+37+66+37+47+86+51+91 + 64+64�=�969
		if(listitem == 0)
		{
			strcat(dlgitem, "����� ��������� ���������� ������� � ��� �� ����� ����������:.\n");
			new weburl[64];
			GetServerVarAsString("weburl", weburl, sizeof(weburl));
			format(dlgitem, sizeof(dlgitem), "%s{FFFFFF}1\t{00FF00}����� �� ������ http://%s/index.php?page=21\n", dlgitem, weburl);
			strcat(dlgitem, "{FFFFFF}2\t{00FF00}������� ������\n");
			strcat(dlgitem, "{FFFFFF}3\t{00FF00}������ ���� ������� ���\n");
			strcat(dlgitem, "{FFFFFF}4\t{00FF00}������� ������� ����� ������ �������� �� ����\n");
			strcat(dlgitem, "{FFFFFF}5\t{00FF00}������ ������ ��������\n��� ��������� �� ���� robokassa.ru\n");
			strcat(dlgitem, "{FFFFFF}6\t{00FF00}������� ������ ������\n��� ��������� �� �������� ������ ������\n");
			format(dlgitem, sizeof(dlgitem), "%s� �������� %s ��� ����� ������� \n", dlgitem, SERVERNAME);
			strcat(dlgitem, "��������� ������, ��������� ��, �������� ������, ����� � ������\n");
			strcat(dlgitem, "{FFFFFF}7\t{00FF00}������ ��� Email(�������� ����)\n");
			strcat(dlgitem, "{FFFFFF}8\t{00FF00}������ '������� � ������'\n��� ��������� �� �������� ����� ������� ������, ��� ���� ������ ����������� �����.\n");
			strcat(dlgitem, "{FFFFFF}9\t{00FF00}� ���� ������� ������� /donat\n");
			strcat(dlgitem, "{FFFFFF}10\t{00FF00}� �������, �������� ������, �� ��� �� ������� ��������� ���� ������.\n");
			new caption[70];
			format(caption, sizeof(caption), "*** ����� *** �������� %.1f �������", PlayerInfo[playerid][pGold]);
			MenuOperation[playerid] = 0;
			ShowPlayerDialogEx(playerid, DIALOG100, DIALOG_STYLE_MSGBOX, caption, dlgitem, "OK", "");
		}
		else if(listitem == 1)
		{
			MenuOperation[playerid] = 1;
			new caption[] = "������� ������� ������ ($)";
			format(dlgitem, sizeof(dlgitem), "����: 1 ������ = 1200$.\
\n�������� %.1f �������.\
\n�� ������ ������ $%d.\
\n������� $ �� ������ ������?\
\n\n\t{8CAA63}�� ��������� ����� ������� OK.", PlayerInfo[playerid][pGold], floatround(PlayerInfo[playerid][pGold]*1200.0));
			ShowPlayerDialogEx(playerid, GOLD_DIALOG, DIALOG_STYLE_INPUT, caption, dlgitem, "OK", "Cancel");
		}
		else if(listitem == 2)
		{
			MenuOperation[playerid] = 2;
			new caption[] = "������ ����� (��������������)";
			format(dlgitem, sizeof(dlgitem), "��������� ������: 50 ������� \n�������� %.1f �������. \n�� �������� ����� � ��� ����?", PlayerInfo[playerid][pGold]);
			ShowPlayerDialogEx(playerid, GOLD_DIALOG, DIALOG_STYLE_MSGBOX, caption, dlgitem, "��", "���");
		}
		else if(listitem == 3)
		{
			MenuOperation[playerid] = 3;
			new caption[] = "�������� ������. ";
			format(dlgitem, sizeof(dlgitem), "���������: 50 �������. \n�������� %.1f �������. \n�� �������� �������� ������?", PlayerInfo[playerid][pGold]);
			ShowPlayerDialogEx(playerid, GOLD_DIALOG, DIALOG_STYLE_MSGBOX, caption, dlgitem, "��", "���");
		}
		else if(listitem == 4)
		{
			MenuOperation[playerid] = 4;
			new caption[] = "�������� ������ ������������";
			format(dlgitem, sizeof(dlgitem), "���������: 50 �������. \n�������� %.1f �������. \n�� �������� �������� ������ ������������?", PlayerInfo[playerid][pGold]);
			ShowPlayerDialogEx(playerid, GOLD_DIALOG, DIALOG_STYLE_MSGBOX, caption, dlgitem, "��", "���");
		}
		else if(listitem == 5)
		{
			VIPHelp(playerid);
		}
	}
//==============================================================================
	else if(MenuOperation[playerid] == 1)
	{
	    if(!strlen(inputtext) || strlen(inputtext) > 10)
	    {
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   �� �� ������� ���-�� ������� ������ ����������� ��� ������� !");
			return 1;
	    }
	    if(strval(inputtext) < 0 || strval(inputtext) >= 2147483647)
	    {
	    	PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   �� ���������� �������� !");
			return 1;
	    }
	    if(strval(inputtext) < 1200)
	    {
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   ����������� ����� $1200 !");
			return 1;
	    }
	  	new Float: gold = strval(inputtext)/1200.0;
	    //if(PlayerInfo[playerid][pGold] > gold)
	    if(floatcmp(PlayerInfo[playerid][pGold], gold) < 0)
	    {
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   � ��� ��� ������� ������� !");
			return 1;
	    }
		SetPVarFloat(playerid, "GOLD", gold);

		new dlgitem[135+35 + 24+3+10+64+10];
		format(dlgitem, sizeof(dlgitem), "%s[%d] ����������:\n\
����� ��� ������:\t������� ������� ������.\n\
�� �����:\t\t$%d\n\
��������:\t\t%s\n\
������ ������:\t\t%.1f �������\n\
\n\n������� Accept, ����� �������.", PlayerName(playerid), playerid, strval(inputtext), HostName, gold);
		new caption[70];
		format(caption, sizeof(caption), "*** ����� *** �������� %.1f �������", PlayerInfo[playerid][pGold]);
		MenuOperation[playerid] = 11;
	 	ShowPlayerDialogEx(playerid, GOLD_DIALOG, DIALOG_STYLE_MSGBOX, caption, dlgitem, "Accept", "Cancel");
	}
	else if(MenuOperation[playerid] == 2)
	{
	    if(PlayerInfo[playerid][pWarns] <= 0)
	    {
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   � ��� ��� �������������� !");
			return 1;
	    }
	    //if(PlayerInfo[playerid][pGold] < 50)
	    if(floatcmp(PlayerInfo[playerid][pGold], 50) <= 0)
	    {
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   � ��� ��� ������� ������� !");
			return 1;
	    }
#if defined vw_sql//#endif
		new ToBase[79+24+10];
		format(ToBase, sizeof(ToBase), "UPDATE `players` SET `Gold`=`Gold`-%d WHERE `Name`='%s'", 50, PlayerName(playerid));// AND `Gold`>=%d
  		//mysql_query(ToBase);
		db_free_result(db_query(db_VW, ToBase));
#endif

		PlayerInfo[playerid][pGold] = floatsub(PlayerInfo[playerid][pGold],50.0);//PlayerInfo[playerid][pGold] -= 50;
		PlayerInfo[playerid][pWarns] --;
		
		format(strings, sizeof(strings), "DONAT %s[%d]: Warns: %d. %d ������� �������" ,
			PlayerName(playerid), playerid, PlayerInfo[playerid][pWarns], 50);
		Log(DONAT, strings);
		
		new dlgitem[135+24+3+10+64+10];
		format(dlgitem, sizeof(dlgitem), "%s[%d]\n\
�������, ��� ��������������� ����� ���������.\n\
���� ����. ���������� ���������� ������: %d\n\
� ������ �������� ����� �������: %d �������\n", PlayerName(playerid), playerid, PlayerInfo[playerid][pWarns], 50);
		new caption[70];
		format(caption, sizeof(caption), "*** ����� *** �������� %.1f �������", PlayerInfo[playerid][pGold]);
		DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0; MenuOperation[playerid] = 0;
	 	ShowPlayerDialogEx(playerid, DIALOG100, DIALOG_STYLE_MSGBOX, caption, dlgitem, "OK", "");

	}
	else if(MenuOperation[playerid] == 3)
	{
	    if(WantedPoints[playerid] <= 0)
	    {
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   � ��� ��� ������� !");
			return 1;
	    }
	    //if(PlayerInfo[playerid][pGold] < 50)
	    if(floatcmp(PlayerInfo[playerid][pGold], 50) <= 0)
	    {
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   � ��� ��� ������� ������� !");
			return 1;
	    }
#if defined vw_sql//#endif
		new ToBase[79+24+10];
		format(ToBase, sizeof(ToBase), "UPDATE `players` SET `Gold`=`Gold`-%d WHERE `Name`='%s'", 50, PlayerName(playerid));// AND `Gold`>=%d
		//mysql_query(ToBase);
		db_free_result(db_query(db_VW, ToBase));
#endif


		PlayerInfo[playerid][pGold] = floatsub(PlayerInfo[playerid][pGold],50.0);//PlayerInfo[playerid][pGold] -= 50;
		ClearCrime(playerid, playerid, 0);
		
		format(strings, sizeof(strings), "DONAT %s[%d]: ClearCrime. %d ������� �������" ,
			PlayerName(playerid), playerid, 50);
		Log(DONAT, strings);

		new dlgitem[135+24+3+10+64+10];
		format(dlgitem, sizeof(dlgitem), "%s[%d]\n\
�������, ��� ��������������� ����� ���������.\n\
������ ������. ����� ������.\n\
� ������ �������� ����� �������: %d �������\n", PlayerName(playerid), playerid, 50);
		new caption[70];
		format(caption, sizeof(caption), "*** ����� *** �������� %.1f �������", PlayerInfo[playerid][pGold]);
		DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0; MenuOperation[playerid] = 0;
	 	ShowPlayerDialogEx(playerid, DIALOG100, DIALOG_STYLE_MSGBOX, caption, dlgitem, "OK", "");
	}
	else if(MenuOperation[playerid] == 4)
	{
	    if(PlayerInfo[playerid][pCrimes] <= 0)
	    {
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   � ��� ��� ������������ !");
			return 1;
	    }
	    //if(PlayerInfo[playerid][pGold] < 50)
	    if(floatcmp(PlayerInfo[playerid][pGold], 50) <= 0)
	    {
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   � ��� ��� ������� ������� !");
			return 1;
	    }
#if defined vw_sql//#endif
		new ToBase[79+24+10];
		format(ToBase, sizeof(ToBase), "UPDATE `players` SET `Gold`=`Gold`-%d WHERE `Name`='%s'", 50, PlayerName(playerid));// AND `Gold`>=%d
		//mysql_query(ToBase);
		db_free_result(db_query(db_VW, ToBase));
		
		format(ToBase, sizeof(ToBase), "DELETE FROM `criminallist` WHERE `Player` = '%s'", PlayerName(playerid));
		//mysql_query(ToBase);
		db_free_result(db_query(db_VW, ToBase));
#endif
		//PlayerInfo[playerid][pGold] -= 50;
		PlayerInfo[playerid][pGold] = floatsub(PlayerInfo[playerid][pGold],50.0);
		PlayerInfo[playerid][pCrimes] = 0;

		format(strings, sizeof(strings), "DONAT %s[%d]: DELETE FROM `criminallist. %d ������� �������" ,
			PlayerName(playerid), playerid, 50);
		Log(DONAT, strings);

		new dlgitem[135+24+3+10+64+10];
		format(dlgitem, sizeof(dlgitem), "%s[%d]\n\
�������, ��� ��������������� ����� ���������.\n\
������ ������������ ������.\n\
� ������ �������� ����� �������: %d �������\n", PlayerName(playerid), playerid, 50);
		new caption[70];
		format(caption, sizeof(caption), "*** ����� *** �������� %.1f �������", PlayerInfo[playerid][pGold]);
		DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0; MenuOperation[playerid] = 0;
	 	ShowPlayerDialogEx(playerid, DIALOG100, DIALOG_STYLE_MSGBOX, caption, dlgitem, "OK", "");
	}
	else if(MenuOperation[playerid] == 5)
	{
/*Examples:
floatcmp(2.0, 2.0) ->  0
floatcmp(1.0, 2.0) -> -1
floatcmp(2.0, 1.0) ->  1*/
	    //if(PlayerInfo[playerid][pGold] < 300)
	   	if(floatcmp(PlayerInfo[playerid][pGold], 300) <= 0)
	    {//���� ������� <= 300
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   � ��� ��� ������� ������� !");
			return 1;
	    }
#if defined vw_sql//#endif
		new ToBase[79+24+10];
		format(ToBase, sizeof(ToBase), "UPDATE `players` SET `Gold`=`Gold`-%d WHERE `Name`='%s'", 300, PlayerName(playerid));// AND `Gold`>=%d
		//mysql_query(ToBase);
		db_free_result(db_query(db_VW, ToBase));
#endif
		//PlayerInfo[playerid][pGold] -= 300.0;
		PlayerInfo[playerid][pGold] = floatsub(PlayerInfo[playerid][pGold],300.0);
		if(PlayerInfo[playerid][pAccount] < getdate())
		{
			PlayerInfo[playerid][pAccount] = (getdate() + 30);
		}
		else PlayerInfo[playerid][pAccount] += 30;

		PlayerInfo[playerid][pSTD] = IsNotBeenIll;

		format(strings, sizeof(strings), "DONAT %s[%d]: ������� ������� �� %s. %d ������� �������" ,
			PlayerName(playerid), playerid, getDate(PlayerInfo[playerid][pAccount]), 300);
		Log(DONAT, strings);
		
		new dlgitem[164 + 24+3 +32+10];
		format(dlgitem, sizeof(dlgitem), "%s[%d]\n\
�������, ��� ��������������� ����� ���������.\n\
�� ������ ������� ������� �� %s, � ��� ��� � ����������.\n\
� ������ �������� ����� �������: %d �������\n", PlayerName(playerid), playerid, getDate(PlayerInfo[playerid][pAccount]), 300);
		new caption[70];
		format(caption, sizeof(caption), "*** ����� *** �������� %.1f �������", PlayerInfo[playerid][pGold]);
		DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0; MenuOperation[playerid] = 0;
	 	ShowPlayerDialogEx(playerid, DIALOG100, DIALOG_STYLE_MSGBOX, caption, dlgitem, "OK", "");
	}
//==============================================================================
//UPDATE `players` SET `Gold`=`Gold`+%d WHERE `Name`='%s' LIMIT 1
	else if(MenuOperation[playerid] == 11)
	{
	    if(PlayerInfo[playerid][pGold] < GetPVarFloat(playerid, "GOLD"))
	    {
	    	DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0;
			SendClientMessage(playerid, COLOR_GREY, "   � ��� ��� ������� ������� !");
			return 1;
	    }
	    

#if defined vw_sql//#endif
		new ToBase[83+24+10];
		//format(ToBase, sizeof(ToBase), "UPDATE `players` SET `Gold`=`Gold`-%.1f WHERE `Name`='%s' AND `Gold`>=%.1f LIMIT 1",
		//	GetPVarFloat(playerid, "GOLD"), PlayerName(playerid), GetPVarFloat(playerid, "GOLD") );
		format(ToBase, sizeof(ToBase), "UPDATE `players` SET `Gold`=`Gold`-%.1f WHERE `Name`='%s'",
			GetPVarFloat(playerid, "GOLD"), PlayerName(playerid) );
		//mysql_query(ToBase);
		db_free_result(db_query(db_VW, ToBase));
#endif

		PlayerInfo[playerid][pGold] = floatsub(PlayerInfo[playerid][pGold], GetPVarFloat(playerid, "GOLD"));
		//PlayerInfo[playerid][pBank] = PlayerInfo[playerid][pBank] + floatround( GetPVarFloat(playerid, "GOLD")*1200.0 );
		GivePlayerMoneyB(fdonat, playerid, floatround( GetPVarFloat(playerid, "GOLD")*1200.0 ));

		new dlgitem[135+24+3+10+64+10];
		format(dlgitem, sizeof(dlgitem), "%s[%d]\n\
�������, ��� ��������������� ����� ���������.\n\
$%d ��������� � ��� �� ���������� ����.\n\
� ������ �������� ����� �������: %.1f �������\n",
			PlayerName(playerid), playerid, floatround( GetPVarFloat(playerid, "GOLD")*1200.0 ), GetPVarFloat(playerid, "GOLD") );

		format(strings, sizeof(strings), "DONAT %s[%d]: $%d ���������. %.1f ������� �������" ,
			PlayerName(playerid), playerid, floatround( GetPVarFloat(playerid, "GOLD")*1200.0 ), GetPVarFloat(playerid, "GOLD"));
		Log(DONAT, strings);

		new caption[70];
		format(caption, sizeof(caption), "*** ����� *** �������� %.1f �������", PlayerInfo[playerid][pGold]);
		DeletePVar(playerid, "GOLD"); PlayerInfo[playerid][pGold] = 0; MenuOperation[playerid] = 0;
	 	ShowPlayerDialogEx(playerid, DIALOG100, DIALOG_STYLE_MSGBOX, caption, dlgitem, "OK", "");

	}
	return 1;
}
