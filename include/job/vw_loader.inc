//��� ���������
/*#define LOADER_DIALOG 52
#define LOADER6_DIALOG 	53

#define LOADER 			18
#define BAG_SLOT 		8//��� ��������� //��� ������� //����� ���� � ���� ��� ����� �����������
new JobAmmount[MAX_PLAYERS];//���-�� ����������� ������//���-�� ������� ����


enum
{
	CP_LOADER_1,//12
	CP_LOADER_2//13
}
//��� ���������

//��� ��������� ����� 16
{true, 2060, 2172.8952,-2256.8610,12.4614,0.0,0.0,44.0},
{true, 2060, 2172.8945,-2256.8603,12.4614,0.0,0.0,43.9947},
{true, 2060, 2172.4230,-2256.4282,12.4609,0.0,0.0,47.2500},
{true, 2060, 2173.3183,-2257.3669,12.4614,0.0,0.0,43.75},
{true, 2060, 2172.7585,-2256.4985,12.7768,0.0,0.0,315.2498},
{true, 2060, 2172.4138,-2256.8581,12.7769,0.0,0.0,316.25},
{true, 2060, 2173.6186,-2257.3120,12.7769,0.0,0.0,136.0},
{true, 2060, 2173.2932,-2257.7080,12.7769,0.0,0.0,134.0},
{true, 2060, 2173.7319,-2257.7785,12.4650,0.0,0.0,42.0},
{true, 2060, 2172.6196,-2256.6328,13.0923,0.0,0.0,0.0},
{true, 2060, 2229.2980,-2286.0588,13.5317,0.0,0.0,226.0},
{true, 2060, 2229.6198,-2286.4582,13.5317,0.0,0.0,45.0},
{true, 2060, 2230.0061,-2286.8173,13.5317,0.0,0.0,44.0},
{true, 2060, 2230.3974,-2287.2316,13.5317,0.0,0.0,44.0},
{true, 2060, 2229.3540,-2286.5485,13.8072,0.0,0.0,134.0},
{true, 2060, 2230.2089,-2286.9531,13.8272,0.0,0.0,102.0},
//��� ��������� ����� 3
{true, 2315, 2232.6596,-2285.5275,12.8755, 0.0,0.0,315.5},
{true, 2315, 2250.3325,-2260.8190,13.1822, 0.0,8.0,314.0},
{true, 2315, 2243.9631,-2267.1560,13.1603, 0.0,8.0,314.0},
*/




new Float:LoaderPoints[4][3] = {
//���������� ����� ��� ����� �����
//{2794.6780,-2448.7661,13.6320},// ����� 1
//{2788.1030,-2449.5293,13.6336},// ����� 2
//{2787.9954,-2462.7532,13.6336},// ����� 3
//{2779.1006,-2462.6292,13.6358}// ����� 4

//���������� ����� ���� ����� �������
{2794.2590,-2425.2559,13.6321},// ����� 1
{2786.0210,-2425.2439,13.6341},// ����� 2
{2785.9568,-2410.0410,13.6341},// ����� 3
{2793.8035,-2410.0559,13.6322}// ����� 4
};


stock loader_OnGameModeInit()
{

	CreateDynamicObject(2029, 2128.29883, -2276.44678, 19.67409,   0.00000, 0.00000, 44.81977);// ������� � ��������� � ����
	CreateDynamicObject(1714, 2129.99976, -2276.76074, 19.53300,   0.00000, 0.00000, 285.19940);// ������� � ��������� � ����

	print("  vw_loader 1.0 By: DANGER1979");
	print("_____________________________________________");
	print(" ");
}

stock loader_OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 5171, 2124.9453, -2275.4531, 20.1406, 0.25); // � ��������� � ���� �������
}

stock loader_OnPlayerStateChange(playerid, newstate)
{
	if(newstate == PLAYER_STATE_WASTED)//����������� ����� ����� ������ ������
	{   //���� ID ������ ��������� ����� ��������� 7
		//��� ��������� STEP0
		if(PlayerInfo[playerid][pJob] == LOADER)
		{
			BizInfo[81][bWorker] --;
			PlayerInfo[playerid][pJob] = 0; gJobDuty[playerid] = 0;
			JobAmmount[playerid] = 0;
			if(IsPlayerAttachedObjectSlotUsed(playerid, BAG_SLOT)) RemovePlayerAttachedObject(playerid, BAG_SLOT);
			//ClearAnimations(playerid, 1);
			ApplyAnimation(playerid, "CARRY","CRRY_PRTIAL",4.1,0,0,0,0,1);
			//SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			DisablePlayerCheckpointEx(playerid);
		}
	}
}

stock loader_OnPlayerInterior(playerid)
{
 	if(PlayerInfo[playerid][pJob] == LOADER)
 	{
 		BizInfo[81][bWorker] --;
	    PlayerInfo[playerid][pJob] = 0;	gJobDuty[playerid] = 0;
		JobAmmount[playerid] = 0;

		if(IsPlayerAttachedObjectSlotUsed(playerid, BAG_SLOT)) RemovePlayerAttachedObject(playerid, BAG_SLOT);
		//ClearAnimations(playerid, 1);
		ApplyAnimation(playerid, "CARRY","CRRY_PRTIAL",4.1,0,0,0,0,1);
		//SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	    SetPlayerSkinEx(playerid, PlayerInfo[playerid][pModel]);
	    DisablePlayerCheckpointEx(playerid);
	    SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� �������� ������ ���������.");
	}
}

stock loader_OnEnterCheckpoint(playerid)
{
	if(CP[playerid] == CP_LOADER_1 && PlayerInfo[playerid][pJob] == LOADER)//��� ��������� STEP4 ������
	{//� �������� �� �����
 	 	if(IsPlayerInAnyVehicle(playerid))
		{
			SendClientMessage(playerid, COLOR_GREY, "   �� �� ������ ���������� �� ���� ������������� �������� !");
		    return 1;
		}

		if(GetTickCount() < (checktimedeliver[playerid]+6000) && !gAnticheat[playerid])
		{
			format(strings, sizeof(strings), "%s[%d] Reset LoadSkill1:%d Mats:%d checktimedeliver:%d[%d] sec",
				PlayerName(playerid),playerid, PlayerInfo[playerid][pLoadSkill], JobAmmount[playerid], (GetTickCount()-checktimedeliver[playerid])/1000, 6);
			Log(JOB, strings);
			PlayerInfo[playerid][pLoadSkill] = 0;
			JobAmmount[playerid] = 0;
			SendClientMessage(playerid, COLOR_GREY, strings);
		    return 1;
		}
		/*format(strings, sizeof(strings), "%s[%d] LoadSkill:%d checktimedeliver:%d sec",
			PlayerName(playerid),playerid, PlayerInfo[playerid][pLoadSkill], (GetTickCount()-checktimedeliver[playerid])/1000);
		Log(JOB, strings);*/

        if(IsPlayerAttachedObjectSlotUsed(playerid, BAG_SLOT)) RemovePlayerAttachedObject(playerid, BAG_SLOT);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        DisablePlayerCheckpointEx(playerid);

		new skill = PlayerInfo[playerid][pLoadSkill];
		new level;
	    if(skill < 50) level = 1;//(1+1)*4=8
	    else if(skill >= 50 && skill < 100) level = 2;//(2+1)*4=12
	    else if(skill >= 100 && skill < 200) level = 3;//(3+1)*4=16
	    else if(skill >= 200 && skill < 400) level = 4;//(4+1)*4=20
	    else if(skill >= 400) level = 5;//(5+1)*4=24

		new package = level;//(level+1);//(level+1)*4;

		new rand;
		do
		{
			if(	(BizInfo[81][bMetal]+package) > LimitMetal &&
				(BizInfo[81][bTextiles]+package) > LimitTextiles &&
				(BizInfo[81][bProvisions]+package) > LimitProvisions &&
				(BizInfo[81][bTree]+package) > LimitTree &&
				(BizInfo[81][bFuel]+package) > LimitFuel)
			{
	  			format(strings, sizeof(strings), "~n~Full Stock in ~p~%s", BizInfo[81][bDiscription]);
				GameTextForPlayerEx(playerid, strings, 5000, 1);
				PlaySoundForPlayer(playerid, SOUND_BASEBALL_BAT_HIT_PED);
				return 1;
			}
			rand = random(5);//0-4
			if(rand == 0 && (BizInfo[81][bMetal]+package) > LimitMetal)
			{
				rand = -1;
			}
			else if(rand == 1 && (BizInfo[81][bTextiles]+package) > LimitTextiles)
			{
				rand = -1;
			}
			else if(rand == 2 && (BizInfo[81][bProvisions]+package) > LimitProvisions)
			{
				rand = -1;
			}
			else if(rand == 3 && (BizInfo[81][bTree]+package) > LimitTree)
			{
				rand = -1;
			}
			else if(rand == 4 && (BizInfo[81][bFuel]+package) > LimitFuel)
			{
				rand = -1;
			}
		}
		while(rand == -1);//����� �� ����� ��� ������ rand != -1 ������, �.�. ������ ��������

        if(rand == 0) BizInfo[81][bMetal] += package;
        else if(rand == 1) BizInfo[81][bTextiles] += package;
        else if(rand == 2) BizInfo[81][bProvisions] += package;
        else if(rand == 3) BizInfo[81][bTree] += package;
		else if(rand == 4) BizInfo[81][bFuel] += package;

        JobAmmount[playerid] += package;

		//���� ������� �����
		new Float: price = compcost*(100+1)/100.0;//15*(100.0+1)/100.0�=�15.15
		//�� �� ���� �������
		new money = floatround(JobAmmount[playerid]*price, floatround_floor);//5*15.15�=�75.75

        format(strings, sizeof(strings), "����������: {33AA33}%d ��{0080FF}. � �������: {33AA33}~$%d", JobAmmount[playerid], money);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, strings);
        SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� ������ �������� ������ � ������ ������!");

		UpdateOceanDock();

		PlayerInfo[playerid][pLoadSkill] ++;
    	level = PlayerInfo[playerid][pLoadSkill];
		if(level == 50)
		{ SendClientMessage(playerid, COLOR_YELLOW, "* ��� ���������������� ������� �������� ������ 2."); }
		else if(level == 100)
		{ SendClientMessage(playerid, COLOR_YELLOW, "* ��� ���������������� ������� �������� ������ 3."); }
		else if(level == 200)
		{ SendClientMessage(playerid, COLOR_YELLOW, "* ��� ���������������� ������� �������� ������ 4."); }
		else if(level == 400)
		{ SendClientMessage(playerid, COLOR_YELLOW, "* ��� ���������������� ������� �������� ������ 5."); }
  	}
	else if(CP[playerid] == CP_LOADER_2 && PlayerInfo[playerid][pJob] == LOADER)//��� ��������� STEP4 ������
	{//�� ������ �� �������
 	 	if(IsPlayerInAnyVehicle(playerid))
		{
			SendClientMessage(playerid, COLOR_GREY, "   �� �� ������ ���������� �� ���� ������������� �������� !");
		    return 1;
		}
		if(GetTickCount() < (checktimedeliver[playerid]+6000) && !gAnticheat[playerid])
		{
			format(strings, sizeof(strings), "%s[%d] Reset LoadSkill2:%d Mats:%d checktimedeliver:%d[%d] sec",
				PlayerName(playerid),playerid, PlayerInfo[playerid][pLoadSkill], JobAmmount[playerid], (GetTickCount()-checktimedeliver[playerid])/1000, 6);
			Log(JOB, strings);
			PlayerInfo[playerid][pLoadSkill] = 0;
			JobAmmount[playerid] = 0;
			SendClientMessage(playerid, COLOR_GREY, strings);
		    return 1;
		}
		/*format(strings, sizeof(strings), "%s[%d] LoadSkill:%d checktimedeliver:%d sec",
			PlayerName(playerid),playerid, PlayerInfo[playerid][pLoadSkill], (GetTickCount()-checktimedeliver[playerid])/1000);
		Log(JOB, strings);*/
        if(IsPlayerAttachedObjectSlotUsed(playerid, BAG_SLOT)) RemovePlayerAttachedObject(playerid, BAG_SLOT);
		//ApplyAnimation(playerid, "CARRY","CRRY_PRTIAL",4.1,0,0,0,0,1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        DisablePlayerCheckpointEx(playerid);
		if(BizInfo[81][bProducts] <= 0)
		{
   			format(strings, sizeof(strings), "~r~Out Of Stock in ~p~%s", BizInfo[81][bDiscription]);
			GameTextForPlayerEx(playerid, strings, 5000, 1);
			PlaySoundForPlayer(playerid, SOUND_BASEBALL_BAT_HIT_PED);
			return 1;
		}
		new package;
		new level = PlayerInfo[playerid][pLoadSkill];
		if(level < 50) { package = 3+random(20); } //3+random(20); }
		else if(level >= 50 && level < 100) { package = 3+random(30); }//3+random(30); }
		else if(level >= 100 && level < 200) { package = 3+random(40); }//3+random(40); }
		else if(level >= 200 && level < 400) { package = 3+random(50); }//3+random(50); }
		else if(level >= 400) { package = 100; }//100; }

		BizInfo[81][bProducts] -= numplayers/2*package;//����� ����� � 100 � ������ ����� ��� ����� ����������
        JobAmmount[playerid] += package;//���-�� �� ��� ������� �������
//���� ������� �����
		new Float: price = compcost*(100+1)/100.0;//15*(100.0+1)/100.0�=�15.15 - ���� ���� ��
//�� ������� ������� ������� ������ 16 ����� 3*15.15*16�=�727.2
//�� ������� ������� ������� ������ 16 ����� 10*15.15*16��=�2424
		//�� �� ���� �������
		new money = floatround(JobAmmount[playerid]*price, floatround_floor);
//�� ��� ������� ��������� 24 ���� 727.2*24��=�17452.8
//�� ��� ������� ��������� 24 ���� 2424*24�=�58176

 		new cost = floatround( numplayers/2*package * compcost*(100+100)/100.0 + package*price, floatround_ceil);//BizInfo[81][bBuyProd] - �.�. ��� ����� 100% ������� �� ������� �� ����
//������� ����
//15 * 15*(100.0+100)/100.0�=�450 - � ����� �������
//450*16�=�7200 - � ����� ������� ��������
//7200*24�=�172800 - �� ���
//172800-87264�=�85536 - ������ ������� ����

//������� ����
//50 * 15*(100.0+100)/100.0�=�1500 - � ����� �������
//1500*16�=�24000 - � ����� ������� ��������
//24000*24�=�576000 - �� ���
//576000-290880�=�285120 - ������ ������� ����
		BizInfo[81][bTill] += cost;
		BizInfo[81][bExport] += cost;

        format(strings, sizeof(strings), "����������: {33AA33}%d ��{0080FF} �������. � �������: {33AA33}~$%d", JobAmmount[playerid], money);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, strings);
        SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� ������ �������� ������ � ������ ������!");

		UpdateOceanDock();

		PlayerInfo[playerid][pLoadSkill] ++;
    	level = PlayerInfo[playerid][pLoadSkill];
		if(level == 50)
		{ SendClientMessage(playerid, COLOR_YELLOW, "* ��� ���������������� ������� �������� ������ 2."); }
		else if(level == 100)
		{ SendClientMessage(playerid, COLOR_YELLOW, "* ��� ���������������� ������� �������� ������ 3."); }
		else if(level == 200)
		{ SendClientMessage(playerid, COLOR_YELLOW, "* ��� ���������������� ������� �������� ������ 4."); }
		else if(level == 400)
		{ SendClientMessage(playerid, COLOR_YELLOW, "* ��� ���������������� ������� �������� ������ 5."); }
  	}
  	return 1;
}

stock loader_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	#pragma unused listitem
	#pragma unused inputtext
	if(!response)
	{
		return 1;
	}
	if(dialogid == LOADER_DIALOG)	//��� ��������� STEP2 ������
	{   //ShowPlayerDialogEx(playerid, LOADER_DIALOG, DIALOG_STYLE_MSGBOX, "����������", dlgitem, "��", "���");
		if(PlayerInfo[playerid][pJob] == LOADER)
		{
		    if(JobAmmount[playerid] != 0) return SendClientMessage(playerid, COLOR_GREY, "   ������� �� ������ �������� �������� � ����� �����.");
			BizInfo[81][bWorker] --;
		    PlayerInfo[playerid][pJob] = 0;	gJobDuty[playerid] = 0;
		    DisablePlayerCheckpointEx(playerid);

			if(IsPlayerAttachedObjectSlotUsed(playerid, BAG_SLOT)) RemovePlayerAttachedObject(playerid, BAG_SLOT);
			ApplyAnimation(playerid, "CARRY","CRRY_PRTIAL",4.1,0,0,0,0,1);
		    SetPlayerSkinEx(playerid, PlayerInfo[playerid][pModel]);

			JobAmmount[playerid] = 0;
			UpdateOceanDock();
   		    SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� �������� ������ ���������.");
		}
		else
		{
			BizInfo[81][bWorker] ++;
			PlayerInfo[playerid][pJob] = LOADER; gJobDuty[playerid] = 1;
			JobAmmount[playerid] = 0;
		    DisablePlayerCheckpointEx(playerid);

		    new skin = random(3);
		    if(skin == 1) SetPlayerSkinEx(playerid, 260);
		    else if(skin == 2) SetPlayerSkinEx(playerid, 27);
			else SetPlayerSkinEx(playerid, 16);
			SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}����� �� �������� �����, ����� ����� �������.");
			SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}����� ��������, ������ ���� � ������, ����� ��������� ������");
		}
	}
	else if(dialogid == LOADER6_DIALOG)//��� ��������� STEP6
	{   //ShowPlayerDialogEx(playerid, LOADER6_DIALOG, DIALOG_STYLE_MSGBOX, "�����", "�� ������ �������� �������� � ��������� ������?", "��", "���");
		if(PlayerInfo[playerid][pJob] != LOADER)
		{
		    SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}������������� � ����������, ����� ������ ������.");
			return 1;
		}
		if(JobAmmount[playerid] <= 0)
		{
		 	SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� �� ����� �� ����� �������.");
			return 1;
		}
		new Float: price = compcost*(100+1)/100.0;//15*(100+1)/100.0�=�15.15
		new money = floatround(JobAmmount[playerid]*price) + BizInfo[81][bSalary];//�� �� ���� �������

		BizInfo[81][bTill] -= money;//���� ������������ ������ ���������
		BizInfo[81][bImport] += money;
	    //GivePlayerMoneyB(fbiz+81, playerid, money);//������ ���� ����� PlayerInfo[playerid][pJob] = 0;
	    GivePlayerMoneyB(fjob+PlayerInfo[playerid][pJob], playerid, money);

	    format(strings, sizeof(strings), "������������: {0080FF}�� ������� {33AA33}$%d {0080FF}. ������� ���.", money);
        SendClientMessage(playerid, COLOR_GREEN, strings);

		BizInfo[81][bWorker] --;
	    PlayerInfo[playerid][pJob] = 0;
		gJobDuty[playerid] = 0;
	    DisablePlayerCheckpointEx(playerid);

		if(IsPlayerAttachedObjectSlotUsed(playerid, BAG_SLOT)) RemovePlayerAttachedObject(playerid, BAG_SLOT);
		ApplyAnimation(playerid, "CARRY","CRRY_PRTIAL",4.1,0,0,0,0,1);
	    SetPlayerSkinEx(playerid, PlayerInfo[playerid][pModel]);

		JobAmmount[playerid] = 0;
		UpdateOceanDock();
	    SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� �������� ������ ���������.");
    }//��� ��������� �����
	return 1;
}


stock loader_OnPlayerKeyStateChange(playerid)
{
	if(PlayerInfo[playerid][pJob] != LOADER) return 1;
	//if(CP[playerid] != 82) return 1;
    if( IsPlayerInRangeOfPoint(playerid, 2.0, 2813.5637,-2464.8813,13.8558)) return 1;
	if(IsPlayerAttachedObjectSlotUsed(playerid, BAG_SLOT))
	{
		RemovePlayerAttachedObject(playerid, BAG_SLOT);
		//ClearAnimations(playerid, 1);
		ApplyAnimation(playerid, "CARRY","CRRY_PRTIAL",4.1,0,0,0,0,1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		DisablePlayerCheckpointEx(playerid);
       	SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� ������ �������!");
	}
	return 1;
}

stock loader_PlayerEnterPickUp(playerid, pickupid)
{
	//--------------------------------------------------------------------------
//��� ��������� STEP1 ������
	if(	pickupid == PickupID[9] &&
		IsPlayerInRangeOfPoint(playerid, 2.1, Pickups[pickupid][p_x],Pickups[pickupid][p_y],Pickups[pickupid][p_z]) )
	{
		if(PlayerInfo[playerid][pInt] != 0) return 1;
		if(PlayerInfo[playerid][pVirtual] != 0) return 1;
		if(PlayerInfo[playerid][pLocal] != FREEROAM) return 1;
		if(gOnDuty[playerid])
		{   //���� ��� � �� �� ��������� � �� � �������
			SendClientMessage(playerid, COLOR_GREY, "   �� �� ������ ����� ��� ������, ����� ����� �� ������ (USE: /duty)!!!");
			return 1;
		}
		if(PlayerInfo[playerid][pJob] != 0 && PlayerInfo[playerid][pJob] != LOADER)
		{
			format(strings, sizeof(strings), "������������: {0080FF}�� �� ������ {FFFFFF}%s{0080FF}. ����� ��������� (USE: /quitjob).", GetPlayerJob(playerid) ); //���������
			SendClientMessage(playerid, COLOR_GREEN, strings);
			return 1;
		}
		if(gJobDuty[playerid])
		{   //���� ��� � �� �� ��������� � �� � �������
			SendClientMessage(playerid, COLOR_GREY, "   �� �� ������ ����� ��� ������, ����� ����� �� ���������!!!");
			return 1;
		}
        /*if(BizInfo[81][bTill] <= 0)
        {
      		SendClientMessage(playerid, COLOR_GREY, "   ��������, ���� ������. � ����� ��� �����.");
      		return 1;
        }*/
		if(PlayerInfo[playerid][pJob] == LOADER)
		{
			ShowPlayerDialogEx(playerid, LOADER_DIALOG, DIALOG_STYLE_MSGBOX, "���������� ���������", "�� ��� ���������� � ������ ��������!\n�� ������ ��������� ������?","��","���");
		}
		else
		{
			new dlgitem[] = "1. ����� ������ ������ �������� ������������� � ������� ������\
\n2. ����� ������������� �� �������� ����� �� ��������\
\n3. �������� ������� �� ����� � ����� �� �����\
\n4. ����� ������� ����������� ��� ���-�� �������\
\n��������� � ����� �� ���������, ��� ��������� ����� � �����������\
\n\n�� ������ �����������, ����� ������ ������?";
			ShowPlayerDialogEx(playerid, LOADER_DIALOG, DIALOG_STYLE_MSGBOX, "���������� ���������", dlgitem, "��", "���");
		}
		//gDialogStatus[playerid][3] = 3;//��� 3 ������ ������� ��� ������ �� ������
		//return 1;
	}
	//��� ��������� STEP5
	else if(pickupid == PickupID[10] &&
			IsPlayerInRangeOfPoint(playerid, 2.1, Pickups[pickupid][p_x],Pickups[pickupid][p_y],Pickups[pickupid][p_z]) )
	{
		if(PlayerInfo[playerid][pJob] == LOADER)//if(PlayerInfo[playerid][pJob] != 19)
		{
			return SendClientMessage(playerid, COLOR_GREY, "   �� �� ������� !");
		}
		if(PlayerInfo[playerid][pJob] == 0)//if(!gJobDuty[playerid])
		{
			//SendClientMessage(playerid, COLOR_GREY, "   �� ��� �� ���������� � ������ !");
			return 1;
		}
		ShowPlayerDialogEx(playerid, LOADER6_DIALOG, DIALOG_STYLE_MSGBOX, "����� ���������", "�� ������ �������� �������� � ��������� ������?", "��", "���");
		//return 1;
	}
	//��� ��������� STEP0
	else if(pickupid == PickupID[11] && IsPlayerInRangeOfPoint(playerid, 2.1, Pickups[pickupid][p_x],Pickups[pickupid][p_y],Pickups[pickupid][p_z]) )
	{
		//if(PlayerInfo[playerid][pJob] != 19) return SendClientMessage(playerid, COLOR_GREY, "   �� �� ������� !");
		new dlgitem[590];
		strcat(dlgitem, "1. ����� ������ ������ �������� ������� � ������� � ������������� � ������� ������.");
		strcat(dlgitem, "\n2. ����� ������������� �� �������� ����� �� ��������.");
		strcat(dlgitem, "\n3. �������� ������� �� ����� � ����� �� �����.");
		strcat(dlgitem, "\n4. ����� ������� ����������� ��� ���-�� �������,");
		strcat(dlgitem, "\n��������� � ����� �� ���������, ��� ��������� � ������ ������.");
		strcat(dlgitem, "\n� ��������� ������ ��� ��������� ����� �����");
		strcat(dlgitem, "\n���������� ����� ����� �������� /skill ������ � ���� ����� 18: �������.");
		strcat(dlgitem, "\n\n�� ������ ������� ����� ������������� �����");
		ShowPlayerDialogEx(playerid, DIALOG100, DIALOG_STYLE_MSGBOX, "�������. ������ �� ������", dlgitem, "��", "");
		//return 1;
	}
//��� ��������� STEP3
	else if(pickupid == PickupID[12] && IsPlayerInRangeOfPoint(playerid, 2.1, Pickups[pickupid][p_x],Pickups[pickupid][p_y],Pickups[pickupid][p_z]))
 	{
		if(PlayerInfo[playerid][pJob] != LOADER)
		{
			//SendClientMessage(playerid, COLOR_GREY, "   �� �� ������� !");
			return 1;
		}
		if(CP[playerid] != 0)
  	    {
  	        SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� ��� ���� �������.");
  	        return 1;
		}
		if(BizInfo[81][bTill] <= (500000+BizInfo[81][bSalary]))
        {
      		SendClientMessage(playerid, COLOR_GREY, "   ��������, � ����� ������ $500000 ��� ����������� ������ ���������������.");
      		SendClientMessage(playerid, COLOR_GREY, "   ���������� ���������� �� �������� ������� �� ������ �� �������.");
      		return 1;
        }
  	    if( IsObjectMoving(gMainShipObjectId) )
  	    {
  	        //SendClientMessage(playerid, COLOR_YELLOW, "����� � ���� (USE: /stopship)");
  	        SendClientMessage(playerid, COLOR_YELLOW, "����� � ����, ��������� ��� � �������.");
  	        return 1;
		}
        new rand = random(sizeof(LoaderPoints));
        CP[playerid] = CP_LOADER_1;
        SetPlayerCheckpointEx(playerid, LoaderPoints[rand][0],LoaderPoints[rand][1],LoaderPoints[rand][2], 2.0);
        //ApplyAnimation(playerid, "CARRY","CRRY_PRTIAL",4.1,1,0,0,1,1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
        //SetPlayerAttachedObjectEx(playerid, BAG_SLOT, 2060, Spine, 0.11,0.36,0.0, 0.0,90.0);//�����
        SetPlayerAttachedObjectEx(playerid, BAG_SLOT, 1220, Spine, 0.3720,0.6190,-0.0269, 0.00,9.10,4.99, 1.00,1.00,1.00);//�������
/*
playerid	ID of the player you want to attach the object to.
index	the index of the object
modelid	The model you want to use.
bone	The bone you want to attach the object to.
fOffsetX	(optional) X axis offset for the object position.
fOffsetY	(optional) Y axis offset for the object position.
fOffsetZ	(optional) Z axis offset for the object position.
fRotX	(optional) X axis rotation of the object.
fRotY	(optional) Y axis rotation of the object.
fRotZ	(optional) Z axis rotation of the object.
fScaleX	(optional) X axis scaling of the object.
fScaley	(optional) Y axis scaling of the object.
fScaleZ	(optional) Z axis scaling of the object.
*/
		checktimedeliver[playerid] = GetTickCount();
		format(strings, sizeof(strings), "��� �������� ������� ��� �� %d ������ � ��� ��������� �����.", 8);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, strings);

        SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� ���� �������. ���� � �� �����.");
		//return 1;
	}
//��� ��������� STEP3
	else if(pickupid == PickupID[13] && IsPlayerInRangeOfPoint(playerid, 2.1, Pickups[pickupid][p_x],Pickups[pickupid][p_y],Pickups[pickupid][p_z])
		&& PlayerInfo[playerid][pJob] == LOADER)
 	{
		if(BizInfo[81][bProducts] <= 0)
		{
   			format(strings, sizeof(strings), "~r~Out Of Stock in ~p~%s", BizInfo[81][bDiscription]);
			GameTextForPlayerEx(playerid, strings, 5000, 1);
			PlaySoundForPlayer(playerid, SOUND_BASEBALL_BAT_HIT_PED);
			return 1;
		}
  	    if( IsObjectMoving(gMainShipObjectId) )
  	    {
  	        //SendClientMessage(playerid, COLOR_YELLOW, "����� � ���� (USE: /stopship)");
  	        SendClientMessage(playerid, COLOR_YELLOW, "����� � ����, ��������� ���� ��� �� �������� � ����.");
  	        return 1;
		}
		if(CP[playerid] != 0)
  	    {
  	        SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� ��� ���� �������.");
  	        return 1;
		}
        CP[playerid] = CP_LOADER_2;
        SetPlayerCheckpointEx(playerid, 2813.5637,-2464.8813,13.8558, 2.0);
        //ApplyAnimation(playerid, "CARRY","CRRY_PRTIAL",4.1,1,0,0,1,1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
        SetPlayerAttachedObjectEx(playerid, BAG_SLOT, 1220, Spine, 0.3720,0.6190,-0.0269, 0.00,9.10,4.99, 1.00,1.00,1.00);//�������

 		checktimedeliver[playerid] = GetTickCount();
		format(strings, sizeof(strings), "��� �������� ������� ��� �� %d ������ � ��� ��������� �����.", 8);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, strings);

        SendClientMessage(playerid, COLOR_GREEN, "������������: {0080FF}�� ���� �������. ���� � �� �������� �����.");
		//return 1;
	}//��� ��������� �����
	return 1;
}