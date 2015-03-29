<?php
/**
 * @file
 * Display Suite One Column Stacked template.
 */
?>

<div class="<?php print $classes;?> clearfix">
  <!-- Needed to activate contextual links. -->
  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if ($top): ?>
    <div class="ds-top<?php print $top_classes; ?>">
      <?php print $top; ?>
    </div>
  <?php endif; ?>
  <?php if ($bottom): ?>
    <div class="ds-bottom<?php print $bottom_classes; ?>">
      <?php print $bottom; ?>
    </div>
  <?php endif; ?>
</div>

<!-- Needed to activate display suite support on forms. -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
