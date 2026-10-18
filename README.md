<p align="center">
  <img alt="Yggdrasilcore" src="https://github.com/user-attachments/assets/6f96adf9-1867-4ca6-b627-1bd0ab7ee494" />
</p>

# Shadows

`mod-shadows` adds player-like bots to a [Yggdrasilcore](https://github.com/yggdrasilcore/yggdrasilcore) server. It is a Yggdrasilcore adaptation of AzerothCore's [mod-playerbots](https://github.com/mod-playerbots/mod-playerbots), which in turn descends from IKE3's Shadows and the mangosbot/playerbots line of projects.

Bots can be your own alt characters or random world wanderers. They party up, quest, level, run dungeons, raids and battlegrounds, and are driven entirely from chat, with extensive configuration for how they behave.

<p align="center">
  <a href="https://github.com/yggdrasilcore/mod-shadows/actions/workflows/core_build.yml"><img src="https://github.com/yggdrasilcore/mod-shadows/actions/workflows/core_build.yml/badge.svg" alt="Build"></a>
  <a href="https://github.com/yggdrasilcore/mod-shadows/actions/workflows/code_style.yml"><img src="https://github.com/yggdrasilcore/mod-shadows/actions/workflows/code_style.yml/badge.svg" alt="Codestyle"></a>
</p>

Read more about Yggdrasil WoW and see Yggdrasilcore in action [here](https://yggdrasilwow.com/).

## Compatibility

> [!IMPORTANT]
> Shadows is built and tested against Yggdrasilcore only. It is not compatible with stock AzerothCore, and its scripts, database tables and configuration are not interchangeable with upstream mod-playerbots.

If you need stock playerbots, use the upstream project: [mod-playerbots/mod-playerbots](https://github.com/mod-playerbots/mod-playerbots).

## What we changed

This fork keeps upstream bot behaviour but hardens it for Yggdrasilcore's threaded core. A non-exhaustive list:

- Renamed the module from playerbots to shadows throughout.
- Thread safety: the holder bot map and the channel, guild and bot snapshots are locked and iterated over copies, and the AI init guard is locked.
- Shutdown: bot AIs are torn down during world shutdown, and crashes from deleting groups and guilds are avoided via manager-owned zombies.
- Movement: bots get gravity and navmesh handling through `MoveJump`, sharper incline/decline handling, and correct engage behaviour when a target has no line of sight (melee closes, ranged repositions).
- Visibility: destroy packets are sent before visibility is wiped on a bot teleport.
- Quality of life: eat/drink no longer sleeps the bot AI, feast items are excluded from food/drink selection, sit persistence is fixed, and follow-on-map-change messages are debounced.
- Build: Ubuntu 24.04 CI against Yggdrasilcore with ccache and Ninja.

## Installation

```bash
cd <yggdrasilcore-path>/modules
git clone https://github.com/yggdrasilcore/mod-shadows.git
```

Then rebuild Yggdrasilcore. Bot behaviour is configured in `conf/shadows.conf.dist`.

## Documentation

- [Generated module documentation](https://yggdrasilcore.github.io/mod-shadows/)
- [AzerothCore installation guide](https://www.azerothcore.org/wiki/installation)

## Support

Shadows is a downstream fork and we do not provide official public support for it, and upstream channels do not support Shadows-specific behaviour. If you use it and find a bug, feel free to open an issue or a pull request here.

## Contributing

Shadows is a privately managed repository. We do not recommend that emulation enthusiasts follow it. Instead, we recommend that enthusiasts contribute to the upstream [mod-playerbots](https://github.com/mod-playerbots/mod-playerbots) project and to [AzerothCore](https://github.com/azerothcore/azerothcore-wotlk).

## Acknowledgements

Shadows would not exist without the upstream projects it builds on:

- [mod-playerbots/mod-playerbots](https://github.com/mod-playerbots/mod-playerbots)
- [IKE3's Shadows](https://github.com/ike3/mangosbot)
- [celguar/mangosbot-bots](https://github.com/celguar/mangosbot-bots)

## License

- Source: This repository is distributed under the GNU Affero General Public License v3.0.
- Intellectual property: Yggdrasil WoW and its derivative projects are not related to Blizzard Entertainment and lay no claim to Blizzard Entertainment's copyrights or intellectual property. They operate solely as an avenue for exploring the functionality of the abandonware WotLK 3.3.5a client in an educational capacity.
