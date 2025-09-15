# So_long Architecture Design

## 🎯 設計目標
- **関心の分離**: ロジック・描画・イベントハンドリングの分離
- **拡張性**: 新機能追加が容易
- **テスタビリティ**: 各レイヤーの独立テストが可能
- **可読性**: 責務が明確で理解しやすい

## 🏗️ アーキテクチャ概要

### MVC + Event-Driven パターン
```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│     View        │    │   Controller    │    │     Model       │
│   (描画層)       │◄──►│   (制御層)       │◄──►│   (状態層)       │
└─────────────────┘    └─────────────────┘    └─────────────────┘
         ▲                       ▲                       ▲
         │                       │                       │
         └───────────────────────┼───────────────────────┘
                                 ▼
                    ┌─────────────────┐
                    │  Event System   │
                    │  (イベント層)     │
                    └─────────────────┘
```

## 📁 ディレクトリ構成

```
src/
├── main.c                    # エントリーポイント・MLXイベント管理
├── game/
│   ├── game_state.c         # ゲーム状態管理
│   └── game_loop.c          # メインゲームループ
├── models/                  # データ・状態管理 (Model層)
│   ├── player_model.c       # プレイヤー状態
│   ├── collectible_model.c  # コレクタブル状態
│   ├── map_model.c          # マップ状態
│   └── game_model.c         # 全体のゲーム状態
├── controllers/             # ビジネスロジック (Controller層)
│   ├── player_controller.c  # プレイヤー移動ロジック
│   ├── collectible_controller.c # コレクタブル取得ロジック
│   ├── collision_controller.c   # 衝突判定ロジック
│   └── game_controller.c    # ゲーム進行制御
├── views/                   # 描画処理 (View層)
│   ├── renderer.c           # 描画エンジン
│   ├── player_view.c        # プレイヤー描画
│   ├── collectible_view.c   # コレクタブル描画
│   └── map_view.c           # マップ描画
├── events/                  # イベントハンドリング
│   ├── input_events.c       # キーボード・マウス入力
│   ├── game_events.c        # ゲーム内イベント
│   └── event_dispatcher.c   # イベント配信システム
└── utils/                   # ユーティリティ
    ├── vector2d.c          # 2D座標計算
    └── timer.c             # タイマー機能
```

## 🔄 データフロー

### 1. 入力処理フロー
```
MLX入力 → Event System → Controller → Model → View → 画面更新
```

### 2. ゲームループフロー
```
1. Input Processing (入力処理)
2. Update Logic (ロジック更新)
3. Collision Detection (衝突判定)
4. State Update (状態更新)
5. Rendering (描画)
```

### 3. State Update と Rendering の詳細な関係

#### State Update Phase (状態更新フェーズ)
```c
// 状態更新の責務
void update_game_state(t_game_state *game, float delta_time) {
    // 1. プレイヤー状態更新
    update_player_state(game->player, delta_time);
    
    // 2. コレクタブル状態更新
    update_collectibles_state(game->collectibles, delta_time);
    
    // 3. ゲーム進行状態更新
    update_game_progress(game);
    
    // 4. 状態変更イベント発火
    if (game->state_changed) {
        trigger_state_change_events(game);
        game->state_changed = false;
    }
}
```

#### Rendering Phase (描画フェーズ)
```c
// 描画の責務：State を読み取り、画面に反映
void render_game(t_game_state *game) {
    // 1. フレームバッファクリア
    clear_screen(game->renderer);
    
    // 2. 背景レイヤー描画
    render_background(game->map, game->renderer);
    
    // 3. ゲームオブジェクト描画（Stateを参照のみ）
    render_collectibles(game->collectibles, game->renderer);
    render_player(game->player, game->renderer);
    
    // 4. UIレイヤー描画
    render_ui(game->move_count, game->score, game->renderer);
    
    // 5. 画面更新
    present_screen(game->renderer);
}
```

#### 重要な設計原則
```
┌─────────────────┐     ┌─────────────────┐
│  State Update   │     │   Rendering     │
│                 │     │                 │
│ ✅ State変更OK   │────▶│ ❌ State変更NG   │
│ ❌ 描画処理NG     │     │ ✅ State読取OK   │
│                 │     │                 │
│ • 位置計算        │     │ • 画面描画      │
│ • 衝突判定        │     │ • スプライト    │
│ • スコア更新      │     │ • エフェクト    │
│ • 状態遷移        │     │ • UI表示       │
└─────────────────┘     └─────────────────┘
```

## 📊 各レイヤーの責務

### Model層 (models/)
- **責務**: データの保持・状態管理
- **特徴**: 描画やイベントに依存しない純粋なデータ
```c
typedef struct s_player_model {
    t_vector2d position;     // 現在位置
    t_vector2d direction;    // 向き
    int health;              // 体力
    int score;               // スコア
} t_player_model;
```

### Controller層 (controllers/)
- **責務**: ビジネスロジック・状態変更
- **特徴**: Modelを操作、Viewに依存しない
```c
// プレイヤー移動ロジック
bool move_player(t_player_model *player, t_vector2d direction, t_map_model *map);
// コレクタブル取得ロジック
bool collect_item(t_player_model *player, t_collectible_model *item);
```

### View層 (views/)
- **責務**: 描画処理のみ
- **特徴**: Modelの状態を読み取り描画、状態変更はしない
```c
// プレイヤー描画
void render_player(t_player_model *player, t_renderer *renderer);
// マップ描画
void render_map(t_map_model *map, t_renderer *renderer);
```

### Event層 (events/)
- **責務**: イベントハンドリング・配信
- **特徴**: MLX入力をゲームロジックに変換
```c
// キー入力イベント
void on_key_pressed(int key, t_game_state *game);
// ゲームイベント
void on_collectible_obtained(t_collectible_model *item, t_game_state *game);
```

## 🎮 具体的な実装例

### GameState (中央状態管理)
```c
typedef struct s_game_state {
    t_player_model      *player;
    t_map_model         *map;
    t_collectible_model *collectibles;
    t_mlx_context       *mlx;
    t_renderer          *renderer;
    int                 move_count;
    bool                is_game_over;
    bool                is_game_clear;
    bool                state_changed;    // 状態変更フラグ
    float               delta_time;       // フレーム間時間
} t_game_state;
```

### State Update と Rendering の実装例

#### 1. プレイヤー移動の完全なフロー
```c
// Event: キー入力受信
void on_move_key_pressed(int key, t_game_state *game) {
    t_vector2d direction = key_to_direction(key);
    
    // Controller: 移動ロジック実行
    if (can_move_to(game->player, direction, game->map)) {
        // State Update: 状態を更新
        move_player_position(game->player, direction);
        game->move_count++;
        game->state_changed = true;
        
        // 副次的な状態更新
        check_collectible_collision(game);
        check_win_condition(game);
    }
    // Rendering は別フェーズで自動実行される
}
```

#### 2. State Update の詳細実装
```c
void update_game_state(t_game_state *game, float delta_time) {
    game->delta_time = delta_time;
    
    // アニメーション状態更新
    update_player_animation(game->player, delta_time);
    update_collectible_animations(game->collectibles, delta_time);
    
    // ゲーム進行チェック
    if (all_collectibles_obtained(game->collectibles)) {
        game->is_game_clear = true;
        game->state_changed = true;
    }
    
    // 状態変更があった場合のみイベント発火
    if (game->state_changed) {
        dispatch_state_change_event(game);
    }
}
```

#### 3. Rendering の詳細実装
```c
void render_game(t_game_state *game) {
    t_renderer *r = game->renderer;
    
    // レイヤー別描画（奥から手前へ）
    
    // Layer 1: 背景
    for (int y = 0; y < game->map->height; y++) {
        for (int x = 0; x < game->map->width; x++) {
            char tile = game->map->tiles[y][x];
            render_tile(r, tile, x, y);
        }
    }
    
    // Layer 2: コレクタブル
    for (int i = 0; i < game->collectibles->count; i++) {
        t_collectible *item = &game->collectibles->items[i];
        if (item->is_active) {  // Stateを読み取るのみ
            render_collectible(r, item);
        }
    }
    
    // Layer 3: プレイヤー
    render_player_sprite(r, game->player);
    
    // Layer 4: UI
    render_move_counter(r, game->move_count);
    render_collectible_counter(r, game->collectibles->obtained_count);
    
    // 最終出力
    mlx_put_image_to_window(game->mlx->ptr, game->mlx->win, r->buffer, 0, 0);
}
```

#### 4. フレームタイミング制御
```c
// メインゲームループ
void game_loop(t_game_state *game) {
    static clock_t last_time = 0;
    clock_t current_time = clock();
    float delta_time = (float)(current_time - last_time) / CLOCKS_PER_SEC;
    
    // 1. 入力処理 (MLXイベントから)
    process_pending_events(game);
    
    // 2. State Update (必ず実行)
    update_game_state(game, delta_time);
    
    // 3. Rendering (State変更時 or 定期的に)
    if (game->state_changed || should_render_frame(delta_time)) {
        render_game(game);
        game->state_changed = false;
    }
    
    last_time = current_time;
}
```

#### 5. パフォーマンス最適化
```c
// 条件付き描画
void optimized_render(t_game_state *game) {
    // 状態変更がない場合はスキップ
    if (!game->state_changed && !game->animation_playing) {
        return;
    }
    
    // 部分描画（変更された領域のみ）
    if (game->player->position_changed) {
        render_player_area(game);
        game->player->position_changed = false;
    }
    
    if (game->collectibles->state_changed) {
        render_collectibles_area(game);
        game->collectibles->state_changed = false;
    }
}
```

### イベントフロー例
```c
// 1. MLXから入力受信
void mlx_key_hook_handler(int key, t_game_state *game) {
    dispatch_input_event(key, game);
}

// 2. イベント処理
void on_move_key_pressed(int key, t_game_state *game) {
    t_vector2d direction = key_to_direction(key);
    if (move_player(game->player, direction, game->map)) {
        game->move_count++;
        check_collectibles(game);
        render_game(game);
    }
}

// 3. 描画更新
void render_game(t_game_state *game) {
    clear_screen(game->renderer);
    render_map(game->map, game->renderer);
    render_player(game->player, game->renderer);
    render_collectibles(game->collectibles, game->renderer);
    present_screen(game->renderer);
}
```

## 🔍 参考アーキテクチャ

### 1. **Unity Component System**
- GameObjectとComponentの分離
- 各Componentが特定の責務を持つ

### 2. **Redux Pattern**
- 単一の状態ツリー
- Action → Reducer → State の一方向データフロー

### 3. **Entity-Component-System (ECS)**
- Entity: ゲームオブジェクトの識別子
- Component: データのみ
- System: ロジック処理

### 4. **Model-View-Controller (MVC)**
- 今回採用するパターン
- 関心の分離が明確

## 💡 実装優先順位

1. **Phase 1**: 基本構造
   - GameState定義
   - 基本的なModel構造
   - シンプルなRenderer

2. **Phase 2**: 移動システム
   - Player Controller
   - Collision Detection
   - Input Events

3. **Phase 3**: ゲームロジック
   - Collectible System
   - Win/Lose Conditions
   - Score Management

4. **Phase 4**: 表現・演出
   - Animation System
   - Sound Effects
   - UI Elements

## 🚀 次のステップ

1. `game_state.h` でGameState構造体を定義
2. 基本的なModel構造を実装
3. シンプルなRenderer実装
4. 移動システムのプロトタイプ作成
