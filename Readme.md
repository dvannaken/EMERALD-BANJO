# Version:  Banjokemon Emerald

# Description
Expanding on the foundation laid by Russell and Co.

# TODO:
* Convert to timer system for animations
	* Timer compiling on Timer branch, but graphics are wonky.
	* Does SOIL lower res?
* ~~On-screen menu~~
* Fix combat/death
* Stairs
* Inventory
* Non-hostile/shop NPCs
* Cool indie graphics
* DLC lol

# ISSUES:
1. __Crash during item pickup__ (not consistently replicable)
	* it seems that lookAt() doesn't print "empty" (or anything) on certain empty tiles. This is probably related.
	* check initialization of loot on board
2. Items spawning in walls
3. Merciless goblins (enemies attack twice)