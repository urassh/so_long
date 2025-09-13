# so_long

42TokyoのGraphics課題「so_long」のプロジェクトです。

## Docker環境での実行方法

### 前提条件（macOS）

1. **XQuartzのインストール**
   ```bash
   brew install --cask xquartz
   ```
   インストール後、一度ログアウト・ログインしてください。

2. **XQuartzの起動**
   XQuartzを起動し、以下の設定を確認：
   - `XQuartz > Preferences > Security`
   - "Allow connections from network clients" にチェック

### セットアップと実行

1. **X11フォワーディングの設定**
   ```bash
   ./setup_x11.sh
   ```

2. **Dockerコンテナのビルドと起動**
   ```bash
   docker-compose up --build -d
   ```

3. **コンテナに入る**
   ```bash
   docker-compose exec so_long bash
   ```

4. **プロジェクトのビルド**
   ```bash
   make
   ```

5. **プログラムの実行**
   ```bash
   ./so_long assets/map/map
   ```

### トラブルシューティング

#### X11フォワーディングのテスト
コンテナ内で以下のコマンドを実行して、X11が正常に動作するかテスト：
```bash
apt-get update && apt-get install -y x11-apps
xeyes
```

#### 権限エラーが出る場合
```bash
xhost +localhost
export DISPLAY=:0
```

### 開発環境

- Ubuntu 22.04
- MinilibX (Linux版)
- Valgrind 3.21.0
- Norminette

### ファイル構成

```
.
├── Dockerfile          # Docker設定
├── compose.yml         # Docker Compose設定
├── setup_x11.sh       # X11セットアップスクリプト
├── Makefile           # ビルド設定
├── src/               # ソースコード
├── includes/          # ヘッダファイル
├── assets/            # マップファイル等
└── minilibx-linux/    # MinilibXライブラリ
```

### Make targets

- `make` または `make all`: プロジェクトをビルド
- `make clean`: オブジェクトファイルを削除
- `make fclean`: オブジェクトファイルと実行ファイルを削除
- `make re`: 再ビルド
