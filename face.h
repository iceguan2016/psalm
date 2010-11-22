/*!
*	@file	face.h
*	@brief	Contains face class
*/

#ifndef __FACE_H__
#define __FACE_H__

#include "vertex.h"
#include "directed_edge.h"

namespace psalm
{

/*!
*	@class face
*	@brief Data for a face of the mesh
*/

class face
{
	public:
		face();

		void add_edge(const directed_edge& edge);
		void add_vertex(vertex* v);
		void add_face_vertex(vertex* v);

		size_t num_edges() const;
		size_t num_vertices() const;

		vertex* get_vertex(size_t i) const; // FIXME: For dev purposes only
		vertex* get_face_vertex(size_t i);
		directed_edge& get_edge(size_t i);

		/*!
		*	@brief Pointer to face point.
		*
		*	Pointer to face point that corresponds to the current
		*	face. This pointer is only set and read during
		*	subdivision algorithms and must \e not be relied on
		*	within other functions.
		*/

		vertex* face_point;

		bool marked; // FIXME: For dev purposes only

	private:
		std::vector<directed_edge> E;
		std::vector<vertex*> V;

		std::vector<vertex*> V_F;

		size_t id;
};

} // end of namespace "psalm"

#endif
