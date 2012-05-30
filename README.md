# Mozc IncogSwicher

Google日本語入力(Mozc)のシークレットモードをMacのメニューバーからオンオフできるようにするヤツ

## ビルド方法

1. [Mozc]のコードをゲットしてビルドします
2. IncogSwitcher.xcodeprojをXcodeで開きます
3. MOZC_DIR変数をMozcのソースがあるディレクトリに書き換えます
4. Xcodeでビルド!

[Mozc]: http://code.google.com/p/mozc/

## 使い方

* IncogSwitcher.appを/Applicationsとかに置いて起動
* メニューバーに G ってのが出る
* 押すとシークレットモードをオンオフできる!
* ログイン時に起動するようにしとくと良さげ

## 原理

Google日本語入力(Mozc)は変換サーバとIMEのフロントエンドがIPCで通信しています。公開されているMozcのコードは、そのままではオープンソース版の変換サーバにつなぎに行こうとしますが、そのへんをごにょごにょして、本チャンのGoogle日本語入力につなぐようにしてます。(LibClasses参照)

## ToDo

* Windows対応
* ライブラリ化してATOKプラグインから呼べると楽しい
