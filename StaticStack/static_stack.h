#ifndef STATIC_STACK_H_INCLUDED
#define STATIC_STACK_H_INCLUDED

#define _STATIC_STACK_MAX_SIZE  100
#define _STATIC_STACK_EMPTY     -1
#define _STATIC_STACK_FULL       0
#define _STATIC_STACK_OK         1

typedef int t_info_static_stack;

typedef struct
{
    int top;
    t_info_static_stack info[_STATIC_STACK_MAX_SIZE];
}t_static_stack;


/** \brief
 *
 * \param s t_static_stack*
 * \return void
 */
void init_static_stack(t_static_stack *s);

/** \brief
 *
 * \param s const t_static_stack*
 * \return int
 */
int is_empty_static_stack(const t_static_stack *s);


/** \brief
 *
 * \param s const t_static_stack*
 * \return int
 */
int is_full_static_stack(const t_static_stack *s);



/** \brief
 *
 * \param s t_static_stack*
 * \param info const t_info_static_stack*
 * \return int
 */
int push_static_stack(t_static_stack *s, const t_info_static_stack *info);


/** \brief
 *
 * \param s t_static_stack*
 * \param info t_info_static_stack*
 * \return int
 */
int pop_static_stack(t_static_stack *s, t_info_static_stack *info);



/** \brief
 *
 * \param s t_static_stack*
 * \param info t_info_static_stack*
 * \return int
 */
int top_static_stack(t_static_stack *s, t_info_static_stack *info);



/** \brief
 *
 * \param s t_static_stack*
 * \return void
 */
void clear_static_stack(t_static_stack *s);

#endif // STATIC_STACK_H_INCLUDED
