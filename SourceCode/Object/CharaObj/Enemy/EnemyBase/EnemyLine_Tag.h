#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// �G�̍s�����C���^�O
    /// </summary>
    static struct EnemyLine_Tag
    {
        std::string APPEAR = "appear";
        std::string REPLACE = "replace";
        std::string REPLACE_2 = "replace_2";
        std::string ACTION = "action";
    }enemyline_tag;


    /// <summary>
    /// ���[�v����p
    /// </summary>
    static std::vector<std::string>EnemyLine_TagAll
    {
        enemyline_tag.APPEAR,       //�G�̏o�����C��
        enemyline_tag.REPLACE,      //�摜�̍����ւ����C��
        enemyline_tag.REPLACE_2,    //�摜�̍����ւ����C��
        enemyline_tag.ACTION,       //�U�����C��
    };

    /// <summary>
    /// �񋓌^�p
    /// </summary>
    enum EnemyLine_TagNum
    {
        appear,
        replace,
        replace_2,
        action,
    };
}