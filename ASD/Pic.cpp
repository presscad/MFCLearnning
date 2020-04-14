#include "Pic.h"


//Pic类构造函数-------------------------------------------------------
Pic::Pic(){
	bg[0].set(288, 512, 0.0 ,0.0);
	bg[1].set(288, 512, 0.28515625,0.0);

	//切割资源图
	bird[0][0].set(48, 48, 0.0, 0.9472656);
	bird[0][1].set(48, 48, 0.0546875, 0.9472656);
	bird[0][2].set(48, 48, 0.109375, 0.9472656); 
	bird[1][0].set(48, 48, 0.1640625, 0.9472656);
	bird[1][1].set(48, 48, 0.21875, 0.6308594);
	bird[1][2].set(48, 48, 0.21875, 0.6816406);
	bird[2][0].set(48, 48, 0.21875, 0.7324219);
	bird[2][1].set(48, 48, 0.21875, 0.7832031);
	bird[2][2].set(48, 48, 0.21875, 0.8339844);

	black.set(32, 32, 0.5703125, 0.40234375);
	
	blink[0].set(10, 10, 0.26953125, 0.6660156);
	blink[1].set(10, 10, 0.26953125, 0.7167969);
	blink[2].set(10, 10, 0.26953125, 0.7675781);
	
	brand_copyright.set(126, 14, 0.86328125, 0.17773438);
	button_menu.set(80, 28, 0.90234375, 0.05078125);
	button_ok.set(80, 28, 0.90234375, 0.08203125);
	button_pause.set(26, 28, 0.23632812, 0.59765625);
	button_play.set(116, 70, 0.6855469, 0.22851562);
	button_rate.set(74, 48, 0.90234375, 0.0);
	button_resume.set(26, 28, 0.65234375, 0.27734375);
	button_score.set(116, 70, 0.8027344, 0.22851562);
	button_share.set(80, 28, 0.5703125, 0.27734375);
	
	font[0].set(24, 44, 0.96875, 0.11328125);
	font[1].set(16, 44, 0.265625, 0.8847656);
	font[2].set(24, 44, 0.5703125, 0.30859375);
	font[3].set(24, 44, 0.59765625, 0.30859375);
    font[4].set(24, 44, 0.625, 0.30859375);
	font[5].set(24, 44, 0.65234375, 0.30859375);
	font[6].set(24, 44, 0.5703125, 0.35546875);
	font[7].set(24, 44, 0.59765625, 0.35546875);
	font[8].set(24, 44, 0.625, 0.35546875);
    font[9].set(24, 44, 0.65234375, 0.35546875);
	
	land.set(336, 112, 0.5703125, 0.0);
	
	medals[0].set(44, 44, 0.23632812, 0.50390625);
	medals[1].set(44, 44, 0.23632812, 0.55078125);
	medals[2].set(44, 44, 0.21875, 0.8847656);
	medals[3].set(44, 44, 0.21875, 0.9316406);
	
	New.set(32, 14, 0.21875, 0.9785156);
	
	number_context[0].set(12, 14, 0.26953125, 0.6308594);
	number_context[1].set(12, 14, 0.26953125, 0.6484375);
	number_context[2].set(12, 14, 0.26953125, 0.6816406);
	number_context[3].set(12, 14, 0.26953125, 0.69921875);
	number_context[4].set(12, 14, 0.26953125, 0.7324219);
	number_context[5].set(12, 14, 0.26953125, 0.75);
	number_context[6].set(12, 14, 0.26953125, 0.7832031);
	number_context[7].set(12, 14, 0.26953125, 0.80078125);
	number_context[8].set(12, 14, 0.26953125, 0.8339844);
	number_context[9].set(12, 14, 0.26953125, 0.8515625);
	number_context[10].set(12, 14, 0.96875, 0.16015625);
	number_score[0].set(16, 20, 0.265625, 0.59765625);
	number_score[1].set(16, 20, 0.265625, 0.9316406);
	number_score[2].set(16, 20, 0.265625, 0.9550781);
	number_score[3].set(16, 20, 0.25390625, 0.9785156);
	number_score[4].set(16, 20, 0.9785156, 0.0);
	number_score[5].set(16, 20, 0.9785156, 0.0234375);
	number_score[6].set(16, 20, 0.984375, 0.05078125);
	number_score[7].set(16, 20, 0.984375, 0.08203125);
	number_score[8].set(16, 20, 0.5703125, 0.47265625);
	number_score[9].set(16, 20, 0.60546875, 0.40234375);
	
	pipe2_down.set(52, 320, 0.0, 0.6308594);
	pipe2_up.set(52, 320, 0.0546875, 0.6308594);
	
	pipe_down.set(52, 320, 0.109375, 0.6308594);
	pipe_up.set(52, 320, 0.1640625, 0.6308594);
	score_panel.set(238, 126, 0.0, 0.50390625);
	text_game_over.set(204, 54, 0.765625, 0.11328125);
	text_ready.set(196, 62, 0.5703125, 0.11328125);
    title.set(178, 48, 0.6855469, 0.17773438);
	tutorial.set(114, 98, 0.5703125, 0.17773438);
	white.set(32, 32, 0.5703125, 0.4375);
}//--------------------------------------------------------------------
