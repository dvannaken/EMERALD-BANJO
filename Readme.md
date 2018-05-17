# Version:  Banjokemon Emerald

# Description
Expanding on the foundation laid by Russell and Co.

# TODO:
* Convert to timer system for animations
* ~~On-screen menu~~
* Fix combat/death
* Stairs
* inventory
* non-hostile/shop NPCs
* Cool indie graphics
* DLC lol

# ISSUES:
1: Crash during item pickup (not consistently replicable)
	* it seems that lookAt() doesn't print "empty" (or anything) on certain empty tiles. This is probably related.
	* check initialization of loot on board
2: Items spawning in walls
2: Merciless goblins (enemies attack twice)