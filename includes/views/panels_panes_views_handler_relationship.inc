<?php

class panels_panes_views_handler_relationship extends views_handler_relationship {
  function query() {
    parent::query();
    if (!strcmp($this->definition['base'], 'realname')) {
      $second_join = new views_join();
      $second_join->definition = array(
        'left_table' => 'realname_' . $this->table,
        'left_field' => 'uid',
        'table' => 'users',
        'field' => 'uid',
      );
      $second_join->construct();
      $second_join->adjusted = TRUE;
      $alias = 'users_' . $this->table;
      $this->query->add_relationship($alias, $second_join, 'users');
      $this->query->add_table('users', NULL, $second_join, $alias);
    }
  }
}