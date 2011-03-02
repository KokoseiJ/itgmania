local vStats = STATSMAN:GetCurStageStats();
local function CreateStats( pnPlayer )
	-- Actor Templates
	local aLabel = LoadFont("Common Normal") .. { Text="..."; InitCommand=cmd(zoom,0.5;shadowlength,1;horizalign,left); };
	local aText = LoadFont("Common Normal") .. { Text="..."; InitCommand=cmd(zoom,0.5;shadowlength,1;horizalign,left); };
	-- DA STATS, JIM!!
	local pnStageStats = vStats:GetPlayerStageStats( pnPlayer );
	-- Organized Stats.
	local tStats = {
		W1			= pnStageStats:GetTapNoteScores('TapNoteScore_W1');
		W2			= pnStageStats:GetTapNoteScores('TapNoteScore_W2');
		W3			= pnStageStats:GetTapNoteScores('TapNoteScore_W3');
		W4			= pnStageStats:GetTapNoteScores('TapNoteScore_W4');
		W5			= pnStageStats:GetTapNoteScores('TapNoteScore_W5');
		Miss		= pnStageStats:GetTapNoteScores('TapNoteScore_Miss');
		HitMine		= pnStageStats:GetTapNoteScores('TapNoteScore_HitMine');
		AvoidMine	= pnStageStats:GetTapNoteScores('TapNoteScore_AvoidMine');
		Held		= pnStageStats:GetHoldNoteScores('HoldNoteScore_Held');
		LetGo		= pnStageStats:GetHoldNoteScores('HoldNoteScore_LetGo');
	};
	-- Organized Equation Values
	local tValues = {
		-- marvcount*7 + perfcount*6 + greatcount*5 + goodcount*4 + boocount*2 + okcount*7
		ITG			= ( tStats["W1"]*7 + tStats["W2"]*6 + tStats["W3"]*5 + tStats["W4"]*4 + tStats["W5"]*2 + tStats["Held"]*7 ), 
		-- (marvcount + perfcount + greatcount + goodcount + boocount + misscount + okcount + ngcount)*7
		ITG_MAX		= ( tStats["W1"] + tStats["W2"] + tStats["W3"] + tStats["W4"] + tStats["W5"] + tStats["Miss"] + tStats["Held"] + tStats["LetGo"] )*7,
		-- marvcount*3 + perfcount*2 + greatcount*1 - boocount*4 - misscount*8 + okcount*6
		MIGS		= ( tStats["W1"]*3 + tStats["W2"]*2 + tStats["W3"] - tStats["W5"]*4 - tStats["Miss"]*8 + tStats["Held"]*6 ),
		-- (marvcount + perfcount + greatcount + goodcount + boocount + misscount)*3 + (okcount + ngcount)*6
		MIGS_MAX	= ( (tStats["W1"] + tStats["W2"] + tStats["W3"] + tStats["W4"] + tStats["W5"] + tStats["Miss"])*3 + (tStats["Held"] + tStats["LetGo"])*6 ),
		
	};
	--
	local t = Def.ActorFrame {};
	t[#t+1] = Def.ActorFrame {
		InitCommand=cmd(y,-34);
		LoadActor(THEME:GetPathG("ScreenTitleMenu","PreferenceFrame")) .. {
			InitCommand=cmd(zoom,0.875;diffuse,PlayerColor( pnPlayer ));
		};
		aLabel .. { Text="ITG DP:"; InitCommand=cmd(x,-64) };
		aText .. { Text=string.format("%04i",tValues["ITG"]); InitCommand=cmd(x,-8;y,5;vertalign,bottom;zoom,0.675); };
		aText .. { Text="/"; InitCommand=cmd(x,28;y,5;vertalign,bottom;zoom,0.5;diffusealpha,0.5); };
		aText .. { Text=string.format("%04i",tValues["ITG_MAX"]); InitCommand=cmd(x,32;y,5;vertalign,bottom;zoom,0.5); };
	};
	t[#t+1] = Def.ActorFrame {
		InitCommand=cmd(y,-6);
		LoadActor(THEME:GetPathG("ScreenTitleMenu","PreferenceFrame")) .. {
			InitCommand=cmd(zoom,0.875;diffuse,PlayerColor( pnPlayer ));
		};
		aLabel .. { Text="MIGS DP:"; InitCommand=cmd(x,-64) };
		aText .. { Text=string.format("%04i",tValues["MIGS"]); InitCommand=cmd(x,-8;y,5;vertalign,bottom;zoom,0.675); };
		aText .. { Text="/"; InitCommand=cmd(x,28;y,5;vertalign,bottom;zoom,0.5;diffusealpha,0.5); };
		aText .. { Text=string.format("%04i",tValues["MIGS_MAX"]); InitCommand=cmd(x,32;y,5;vertalign,bottom;zoom,0.5); };
	};
	return t
end;
local t = Def.ActorFrame {};
t[#t+1] = Def.ActorFrame {
	InitCommand=cmd(x,math.floor(SCREEN_CENTER_X*0.5)-8;y,SCREEN_CENTER_Y);
	--
	CreateStats( PLAYER_1 );
};
return t