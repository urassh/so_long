# MinilibX API リファレンス

MinilibXは42Schoolのプロジェクトで使用されるシンプルなグラフィックライブラリです。

## 基本的な初期化

### mlx_init
```c
void *mlx_init(void);
```
- MinilibXを初期化します
- 戻り値: mlx接続識別子（失敗時はNULL）

### mlx_new_window
```c
void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
```
- 新しいウィンドウを作成します
- パラメータ:
  - `mlx_ptr`: mlx_init()で取得した識別子
  - `size_x`: ウィンドウの幅
  - `size_y`: ウィンドウの高さ
  - `title`: ウィンドウのタイトル
- 戻り値: ウィンドウ識別子（失敗時はNULL）

## 画像処理

### mlx_new_image
```c
void *mlx_new_image(void *mlx_ptr, int width, int height);
```
- 新しい画像を作成します
- 戻り値: 画像識別子

### mlx_get_data_addr
```c
char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
```
- 画像のピクセルデータにアクセスするためのアドレスを取得
- パラメータ:
  - `img_ptr`: 画像識別子
  - `bits_per_pixel`: ピクセルあたりのビット数（出力）
  - `size_line`: 1行あたりのバイト数（出力）
  - `endian`: エンディアン情報（出力）

### mlx_put_image_to_window
```c
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
```
- 画像をウィンドウに描画します
- パラメータ:
  - `x`, `y`: 描画位置

### mlx_xpm_file_to_image
```c
void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
```
- XPMファイルから画像を読み込みます
- パラメータ:
  - `filename`: XPMファイルのパス
  - `width`, `height`: 画像のサイズ（出力）

## イベント処理

### mlx_loop
```c
int mlx_loop(void *mlx_ptr);
```
- イベントループを開始します（メインループ）

### mlx_loop_hook
```c
int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
```
- ループごとに呼び出される関数を設定

### mlx_hook
```c
int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
```
- 特定のイベントに対するハンドラーを設定
- 主要なイベント:
  - `2`: KeyPress
  - `3`: KeyRelease
  - `4`: ButtonPress
  - `5`: ButtonRelease
  - `6`: MotionNotify
  - `17`: DestroyNotify（ウィンドウを閉じる）

### mlx_key_hook
```c
int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
```
- キー押下イベントのハンドラーを設定

### mlx_mouse_hook
```c
int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
```
- マウスクリックイベントのハンドラーを設定

## キーコード

よく使用されるキーコード（macOS）:
- `53`: ESC
- `0`: A
- `1`: S  
- `2`: D
- `13`: W
- `123`: 左矢印
- `124`: 右矢印
- `125`: 下矢印
- `126`: 上矢印

## 描画関数

### mlx_pixel_put
```c
int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
```
- ウィンドウに1つのピクセルを描画

### mlx_string_put
```c
int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
```
- 文字列をウィンドウに描画

## メモリ管理

### mlx_destroy_image
```c
int mlx_destroy_image(void *mlx_ptr, void *img_ptr);
```
- 画像を破棄してメモリを解放

### mlx_destroy_window
```c
int mlx_destroy_window(void *mlx_ptr, void *win_ptr);
```
- ウィンドウを破棄

## 基本的な使用例

```c
#include "mlx.h"

int main(void)
{
    void *mlx;
    void *win;
    
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "My Window");
    
    mlx_loop(mlx);
    return (0);
}
```

## コンパイル

```bash
gcc -Wall -Wextra -Werror -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz main.c
```

## 色の指定

色は16進数で指定します：
- `0x000000`: 黒
- `0xFFFFFF`: 白  
- `0xFF0000`: 赤
- `0x00FF00`: 緑
- `0x0000FF`: 青

RGB値の計算：
```c
int color = (r << 16) + (g << 8) + b;
```

## 注意点

1. すべての画像とウィンドウは適切に破棄する必要があります
2. イベントループは最後に呼び出します
3. ウィンドウを閉じるイベント（X17）を適切に処理してプログラムを終了できるようにしましょう
4. 画像のピクセル操作は`mlx_get_data_addr`で取得したアドレスを使用します
