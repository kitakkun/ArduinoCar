# 情報工学実験III 作業リポジトリ

情報工学実験IIIで扱うソフトウェアをチームで開発する作業リポジトリです。

## 開発ガイドライン

- `develop`ブランチには直接コミットしない（ブランチを切って作業しよう！）
- コミットメッセージには加えた変更を完結にわかりやすく書く

## 作業フロー

1. `develop`から`feature/xxxx`ブランチを切る
2. `feature/xxxx`内で機能開発を進める
3. 完成したら`develop`に向けてPull Requestを作成・レビュー依頼
4. 指摘された箇所を修正
5. Approve（承認）を貰ったら自分で`develop`にマージ

### 補足

- `feature/xxxx`の`xxxx`は適当な名前。何のタスクをやっているのか想像しやすい命名にしよう。例）`feature/line_trace_algorithm` など
- Pull Requestは作業完了前に作成しても構いません。互いにタスクの進み具合を把握するためにも、Pull Requestを発行した状態で作業を進めていくことを推奨します。

## 使用ツール

強制はしませんが、下記のツールを使用することを推奨します。

- JetBrains CLion (https://www.jetbrains.com/clion/)
- PlatformIO (https://platformio.org/)

Arduino IDEでも可能ではありますが、セットアップが面倒なので非推奨です。

## トラブルシューティング
- ヘッダーファイル内のインクルードにエラーが出てしまう。
    - `platformio init --board uno`を走らせてみてください。多分消えると思う。
    - 上記でも無理ならCLionのプロジェクトを再作成するとき、当プロジェクトのフォルダを選択した状態で、PlatformIOプロジェクト（Arduino Uno）を「Create from Existing Sources」すれば解消されるかも。