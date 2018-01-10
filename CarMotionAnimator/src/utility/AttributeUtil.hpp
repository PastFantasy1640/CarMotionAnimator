//TODO:形式整えて

#include <MFnAttribute.h>

namespace cma{

/** アトリビュートのフラグ設定を簡単に行うためのユーティリティー関数
 * ただし、それぞれの関数で挙動が異なるため、リファレンスは厳重に確認して下さい。
 * @version 1.0
 * @author S.Shirao
 * @see MFnAttribute
 */

/**
 * アトリビュートを設定します。ほぼすべてのパラメータを設定します。
 * また、ここに用意してあるパラメータは特殊で、-1と指定した場合は「変更しない」、1と指定した場合は「true」、0と指定した場合は「false」と指定されます。
 * パラメータによるバグを防ぐため、-1, 0, 1以外を指定した場合はMStatusExceptionのInvalidParameterを投げます。
 * Mayaのデフォルトに良きに計らってもらう場合は-1を指定しておいて下さい。
 * また、2018/01現在のMayaAPIリファレンスよりデフォルトを角括弧にて示します。
 * @see MFnAttribute
 * @param readable 読み取ることができるか。trueの場合、他のノードのデータソースとして使用することができます。[true]
 * @param writable 書き込むことができるか。trueの場合、他のノードの出力を接続でき、setAttrコマンドも成功します。またkeyableとともにtrueにすることで、チャンネルボックスに項目が表示されます。[true]
 * @param connectable 他のノードと接続ができるか。[true]
 * @param storable ファイルへデータを保存できるか。[true]
 * @param cached 計算結果をメモリーへキャッシュできるか。[true]
 * @param array データが配列であるか。他のノードから複数の接続が必要な場合はtrueである必要があります。[false]
 * @param index_matters データが配列かつ読み込み不可(unreadable)であるときに、
 */
extern void setAttrbuteFlags(
    MFnAttribute * attribute,
    const int readable = -1,
    const int writable = -1,
    const int storable = -1,
    const int connectable = -1,
    const int cached = -1,
    const int array = -1,
    const int index_matters = -1,
    const int keyable = -1,
    const int channelbox = -1,
    const int hidden = -1,
    const int used_as_color = -1,
    const int indeterminant = -1,
    const int internal = -1
);

extern void setAttributeFlagsInputPreset(
    MFnAttribute * attribute,
    const bool readable = true,
    const bool array = false,
    const bool keyable = false,
    const bool hidden = false,
    const bool used_as_color = false
);

extern void setAttributeFlagsOutputPreset(
    MFnAttribute * attribute,
    const bool storable = true,
    const bool cached = true, 
    const bool array = false,
    const bool keyable = false,
    const bool channelbox = false,
    const bool hidden = false,
    const bool used_as_color = false,
);

}
