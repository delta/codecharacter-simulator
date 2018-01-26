#ifndef PLAYER_CODE_PLAYER_CODE_H
#define PLAYER_CODE_PLAYER_CODE_H

#include "player_code/player_code_export.h"
#include "player_wrapper/interfaces/i_player_code.h"
#include "state/player_state.h"

namespace player_code {

/**
 * Class where player defines AI code
 */
class PLAYER_CODE_EXPORT PlayerCode : public player_wrapper::IPlayerCode {
  private:
	player_state::State *player_state;

  public:
	PlayerCode(player_state::State *player_state);

	/**
	 * Player AI update function (main logic of the AI)
	 */
	void Update() override;
};
}

#endif
