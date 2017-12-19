/**
 * @file logger.h
 * Declarations for the logger class
 */

#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include "game.pb.h"
#include "logger/interfaces/i_logger.h"
#include "logger/logger_export.h"
#include "state/interfaces/i_state.h"
#include <cstdint>
#include <memory>
#include <ostream>
#include <vector>

namespace logger {

/**
 * Logger class that takes the current game state and logs information
 * Writes log to file system after game is complete
 */
class LOGGER_EXPORT Logger : public ILogger {
  private:
	/**
	 * Number of turns since the start of the game
	 */
	int64_t turn_count;

	/**
	 * Protobuf object holding complete game logs
	 */
	std::unique_ptr<proto::Game> logs;

  public:
	/**
	 * Constructor for the Logger class
	 */
	Logger();

	/**
	 * @see ILogger#LogState
	 */
	void LogState(state::IState *state) override;

	/**
	 * @see ILogger#WriteGame
	 * Defaults to std::cout when no stream passed
	 */
	void WriteGame(std::ostream &write_stream = std::cout) override;
};
}

#endif
