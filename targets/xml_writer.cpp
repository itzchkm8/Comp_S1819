#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

//---------------------------------------------------------------------------

void m19::xml_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void m19::xml_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

void m19::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_continue_node(m19::continue_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

void m19::xml_writer::do_break_node(m19::break_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void m19::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  process_literal(node, lvl);
}

void m19::xml_writer::do_double_node(cdk::double_node * const node, int lvl) {
  process_literal(node, lvl);
}

void m19::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  process_literal(node, lvl);
}

//---------------------------------------------------------------------------

void m19::xml_writer::do_unary_expression(cdk::unary_expression_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  do_unary_expression(node, lvl);
}

void m19::xml_writer::do_ref_node(m19::ref_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 2);
  closeTag(node, lvl);
  //do_unary_expression(node, lvl); //FIXME ?
}

void m19::xml_writer::do_alloc_node(m19::alloc_node * const node, int lvl) {
  do_unary_expression(node, lvl);
}

void m19::xml_writer::do_not_node(cdk::not_node * const node, int lvl) {
  do_unary_expression(node, lvl);  
}

//---------------------------------------------------------------------------

void m19::xml_writer::do_binary_expression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void m19::xml_writer::do_and_node(cdk::and_node * const node, int lvl) {
  do_binary_expression(node, lvl);  
}
void m19::xml_writer::do_or_node(cdk::or_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}

//---------------------------------------------------------------------------

void m19::xml_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->name() << "</" << node->label() << ">" << std::endl;
}

void m19::xml_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

void m19::xml_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  node->lvalue()->accept(this, lvl);
  reset_new_symbol();

  node->rvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void m19::xml_writer::do_evaluation_node(m19::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_print_node(m19::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void m19::xml_writer::do_read_node(m19::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void m19::xml_writer::do_for_node(m19::for_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  openTag("init", lvl + 2);
  node->init()->accept(this, lvl + 4);
  closeTag("init", lvl + 2);

  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);

  openTag("after", lvl + 2);
  node->after()->accept(this, lvl + 4);
  closeTag("after", lvl + 2);

  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);

  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void m19::xml_writer::do_if_node(m19::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_if_else_node(m19::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_index_node(m19::index_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  openTag("base", lvl + 2);
  node->base()->accept(this, lvl + 4);
  closeTag("base", lvl + 2);

  openTag("index", lvl + 2);
  node->index()->accept(this, lvl + 4);
  closeTag("index", lvl + 2);

  closeTag(node, lvl);
}

void m19::xml_writer::do_block_node(m19::block_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS; // preciso??
  openTag(node, lvl);
  openTag("declarations", lvl + 2);
  do_sequence_node(node->declarations(), lvl + 4);
  closeTag("declarations", lvl + 2);

  openTag("instructions", lvl + 2);
  do_sequence_node(node->instructions(), lvl + 4);
  closeTag("instructions", lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_return_node(m19::return_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

void m19::xml_writer::do_fun_init_section_node(m19::fun_init_section_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->block()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_fun_final_section_node(m19::fun_final_section_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->block()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_fun_section_node(m19::fun_section_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->block()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_fun_body_node(m19::fun_body_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->initial_node()->accept(this, lvl + 2);
  node->sections()->accept(this, lvl + 2);
  node->final_node()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_return_val_node(m19::return_val_node * const node, int lvl) {
  //FIXME
}

void m19::xml_writer::do_fun_call_node(m19::fun_call_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag('identifier', lvl + 2);
  os() << std::string(lvl + 4, ' ') << node->identifier() << std::endl;
  closeTag('identifier', lvl + 2);

  openTag('arguments', lvl + 2);
  node->arguments()->accept(this, lvl + 4);
  closeTag('arguments', lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_var_decl_node(m19::var_decl_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag('identifier', lvl + 2);
  os() << std::string(lvl + 4, ' ') << node->identifier() << std::endl;
  closeTag('identifier', lvl + 2);

  openTag('arguments', lvl + 2);
  node->arguments()->accept(this, lvl + 4);
  closeTag('arguments', lvl + 2);
  closeTag(node, lvl);
}

void m19::xml_writer::do_fun_decl_node(m19::fun_decl_node * const node, int lvl) {
  //FIXME
}

void m19::xml_writer::do_fun_def_node(m19::fun_def_node * const node, int lvl) {
  //FIXME
}

void m19::xml_writer::do_id_node(m19::id_node * const node, int lvl) {
  //FIXME
}