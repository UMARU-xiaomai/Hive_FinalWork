# Hive - 上海大学2024Fall算法与编程课程项目 - 第八组

## 基础游戏规则

[点我尝试一下可视化教程](https://zh-cn.boardgamearena.com/gamepanel?game=hive)

1. 在每个回合里，玩家将选择放置一枚棋子，或移动一枚棋子。 游戏开始时，桌上是空的，所以我们得先放置一枚棋子。
2. 所放置的棋子，必须跟你已放置的己方棋子相连，可是又不可以碰触你对手的任何棋子。
3. 你必须先放置你的蜂后，之后才能移动你已放置的棋子，必须在游戏的前四个回合放置蜂后
4. 各昆虫行进规则
    1. 3蚱蜢可以直线跃过一个或多个棋子。
    2. 3蚂蚁可以从它们的当前位置沿着蜂房边缘移动到周围的任何位置
    3. 2像蚂蚁一样，蜘蛛沿着蜂房的边缘移动。 但跟蚂蚁不同的，是它每次只能移动正好 3 格。
	  4. 2甲虫可以往任何方向移动一格（前提是此移动不分裂蜂房），而且还有自己的特殊能力：它们可以跳到蜂房上方。堆叠高度不限
	  5. 1蜂后只能沿着蜂房边缘移动，每次一格，类似于国际象棋中的国王。
5. 移动任何棋子必须保证不能使蜂房断裂（包括断裂后又接上）
6. 如果某开口处太窄，实体上无法直出穿过，你也不可以移动该棋。唯有甲虫和蚱蜢是例外，它们在蜂房并非水平移动的。
7. 要赢得游戏，你必须包围你对手的蜂后的全六边。包围蜂后的棋子，不计棋色。 

## 项目成员及分工（排名不分先后）

- 杨博文
- 胡永时
- 黄畅
- 王浩宇
- 周圣淞

## 类结构设计（初步设计，实际存在差异）

### 类 Game - 周圣淞

#### 职责: 管理游戏的整体流程，包括玩家回合、胜负判定和游戏状态。

#### 属性:

- players: [Player] - 玩家列表（两名玩家）。
- board: Board - 游戏棋盘对象。
- currentPlayer: Player - 当前回合的玩家。
- isGameOver: bool - 游戏是否结束的标志。

#### 方法:
- start() - 启动游戏。
- playTurn() - 执行当前玩家的回合操作。
- checkGameOver() - 检查游戏是否结束并确定胜者。
- switchPlayer() - 切换到下一个玩家。

### 类 Player

#### 职责: 表示一个玩家，管理其手中的昆虫棋子。
#### 属性:
- name: string - 玩家姓名。
- isAI: bool - 是否为AI玩家的标志。
- pieces: [Piece] - 玩家持有的昆虫棋子列表。
#### 方法:
- selectPiece(board: Board) -> Piece - 选择一个要操作的昆虫棋子。
- placePiece(board: Board, position: Position) - 将棋子放置在棋盘上。
- movePiece(piece: Piece, board: Board, newPosition: Position) - 移动棋子到新位置。

### 类 Board

#### 职责: 表示游戏棋盘，管理棋盘上的位置及棋子。
#### 属性:
- cells: [[Cell]] - 棋盘的格子列表，每个格子可能包含一个棋子。
#### 方法:
- isPositionOccupied(position: Position) -> bool - 检查某个位置是否被占用。
- getValidMoves(piece: Piece) -> [Position] - 获取某个棋子在当前棋盘上的合法移动位置。
- placePiece(piece: Piece, position: Position) - 将棋子放置到指定位置。
- movePiece(piece: Piece, newPosition: Position) - 移动棋子到新位置。

### 类 Piece

#### 职责: 表示一个昆虫棋子，定义棋子的移动规则。
#### 属性:
- type: PieceType - 昆虫类型（如QueenBee, Spider, Ant等）。
- currentPosition: Position - 当前所在位置。
#### 方法:
- getValidMoves(board: Board) -> [Position] - 获取该棋子在当前棋盘上的合法移动位置（每种昆虫的实现不同）。
### 类 Position

#### 职责: 表示棋盘上的一个位置。
#### 属性:
- x: int - 位置的x坐标。
- y: int - 位置的y坐标。
#### 方法:
- isAdjacentTo(other: Position) -> bool - 检查两个位置是否相邻。
### 类 Cell

#### 职责: 表示棋盘上的一个单元格。
#### 属性:
- position: Position - 单元格的位置。
- piece: Optional[Piece] - 单元格上的棋子（如果有）。
#### 方法:
- isEmpty() -> bool - 检查单元格是否为空。
### 类 AIPlayer (继承自 Player)

#### 职责: 表示AI玩家，自动选择棋子和位置进行操作。
#### 方法:
- selectPiece(board: Board) -> Piece - 重写父类方法，根据AI逻辑选择棋子。
- placePiece(board: Board, position: Position) - 重写父类方法，根据AI逻辑放置棋子。
- movePiece(piece: Piece, board: Board, newPosition: Position) - 重写父类方法，根据AI逻辑移动棋子。
