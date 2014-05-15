#ifndef _NODEBOX_H_INCLUDED_
#define _NODEBOX_H_INCLUDED_

#include "common.h"
#include "EditorState.h"

class EditorState;
class NodeBox
{
public:
	NodeBox()
	{}

	NodeBox(stringw name, vector3df one, vector3df two) :
		name(name), one(one), two(two), model(NULL)
	{}

	~NodeBox()
	{
		if (model)
			model->remove();
	}

	irr::core::vector3df one;
	irr::core::vector3df two;
	stringw name;
	irr::scene::IMeshSceneNode* model;

	irr::core::vector3df GetCenter()
	{
		return vector3df(
			one.X + ((two.X - one.X)/2),
			one.Y + ((two.Y - one.Y)/2),
			one.Z + ((two.Z - one.Z)/2)
		);
	}
	irr::core::vector3df GetScale()
	{
		return vector3df(
			(two.X - one.X)/2,
			(two.Y - one.Y)/2,
			(two.Z - one.Z)/2
		);
	}
	void resizeNodeBoxFace(EditorState* editor,CDR_TYPE type,vector3df position,bool both);
	void moveNodeBox(EditorState* editor,CDR_TYPE type,vector3df position);
	void buildNode(vector3di nd_position,IrrlichtDevice* device);
};

#endif
