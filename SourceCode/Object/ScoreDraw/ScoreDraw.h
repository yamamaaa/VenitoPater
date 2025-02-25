#pragma once

#include"../../Object/ObjectBase/ObjectBase.h"


/// <summary>
/// ��ʃT�C�Y�֘A
/// </summary>
namespace GameSystem
{
	class Window;
}

namespace object
{
    /// <summary>
    /// �X�R�A�֘A
    /// </summary>
    class ScoreDraw :public ObjectBase
    {
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		ScoreDraw();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~ScoreDraw();

	private:

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		void LoadObject() override;

		/// <summary>
		/// �n�C�X�R�A�̎擾
		/// </summary>
		void HighScoreGet();

		/// <summary>
		/// �n�C�X�R�A�̃Z�b�g
		/// </summary>
		void HighScoreSet();

		/// <summary>
		/// �X�V
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		void UpdateObj(const float deltatime) override;

		/// <summary>
		/// �\���p�X�R�A�̃Z�b�g
		/// </summary>
		/// <param name="drawobj">�\���pobj</param>
		/// <param name="ans">����</param>
		/// <param name="isset">�Z�b�g���邩</param>
		/// <param name="deltatime">�f���^�^�C��</param>
		void DrawScoreSet(int& drawobj, int ans, bool& isset, const float deltatime);

		/// <summary>
		/// �N���b�NUi�̃A�j���[�V�������s��
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		void ClickUiMoveAnim(const float deltatime);

		/// <summary>
		/// �n�C�X�R�A�̕\��
		/// </summary>
		void HighScoreDraw();

		/// <summary>
		/// �`��
		/// </summary>
		void DrawObj()override;

		std::string m_JsonTag[6];	//�T�E���h�pJson�^�O

		GameSystem::Window* window;
		POINTS m_WindowSize;

		int m_FontHandle_Text;		//�t�H���g�n���h��_�e�L�X�g
		int m_FontHandle_Score;		//�t�H���g�n���h��_�X�R�A
		int m_FontHandle_Item;		//�t�H���g�n���h��_�A�C�e����

		const POINTS m_FONTSIZE_TEXT = { 30,10 };	 //�t�H���g�T�C�Y_�e�L�X�g
		const POINTS m_FONTSIZE_SCORE = { 150,60 };  //�t�H���g�T�C�Y_�X�R�A
		const POINTS m_FONTSIZE_ITEM = { 100,20 };     //�t�H���g�T�C�Y_�A�C�e����

		POINTFLOAT m_UiPos;		//�N���b�NUi���W
		POINTFLOAT m_NItem_Pos; //�A�C�e�������W_�m�[�}��
		POINTFLOAT m_RItem_Pos; //�A�C�e�������W_���A

		std::string m_ItemText = "%d��";
		std::string m_ScoreText = "%d�_";

		float m_Compute_Spped;							//�v�Z�X�s�[�h
		const float m_COMPUTE_SPEED_ITEM = 240.0f;		//�v�Z�X�s�[�h_�A�C�e��
		const float m_COMPUTE_SPEED_SCORE = 2400.0f;	//�v�Z�X�s�[�h_�X�R�A

		const float m_COUNT_DECREMENT = 2.4f;	//�J�E���g���炵��
		const float m_WEIT_MAX = 2.4f;			//�҂�����

		bool m_IsNItemSet;		//�A�C�e�������Z�b�g������_�m�[�}��
		bool m_IsRItemSet;		//�A�C�e�������Z�b�g���邩
		bool m_IsScoreSet;		//�X�R�A���Z�b�g������

		bool m_IsWait;		//�҂����Ԃ�݂��邩
		bool m_CanClick;	//�N���b�N�ł��邩
		bool m_IsClick;		//�N���b�N������

		float m_WaitCount;	//�҂����ԃJ�E���g

		int m_Score;		//�X�R�A
		int m_Score_Draw;	//�X�R�A_�\���p
		int m_HighScore;	//�n�C�X�R�A
		int m_HighScore_Draw;	//�n�C�X�R�A_�\���p

		bool m_IsHighScore_Up;		//�n�C�X�R�A���X�V������

		int m_NItemNum;		//�A�C�e������_�m�[�}��
		int m_NItem_Draw;	//�A�C�e��_�\���p_�m�[�}��

		int m_RItemNum;		//�A�C�e������_���A
		int m_RItem_Draw;	//�A�C�e��_�\���p_���A

		bool m_IsMove_Up;       //�ړ���������ɐ؂�ւ��邩

		const float m_MOVESPEED = 30.0f;						//�ړ��X�s�[�h
		const float m_MOVEPOS_MAX = 3.0f;						//�N���b�NUi�ړ��ʍő�l
		const POINTFLOAT m_UIPOS_RESET = { 910,1015 };		    //�N���b�NUi�����ʒu

		VECTOR m_NowColor;                             //���݂̕����F
		const VECTOR m_COLOR_DEFAULT = VGet(255, 255, 255);  //���F
    };
}