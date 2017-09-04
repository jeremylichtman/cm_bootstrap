var gulp = require('gulp');
var sass = require('gulp-sass');
var concat = require('gulp-concat');
var exec = require('child_process').exec;

// Pattern lab task compile
gulp.task('plab', function (cb) {
  exec('php ./patternlab/core/console --generate', function (err, stdout, stderr) {
    console.log(stdout);
    console.log(stderr);
    cb(err);
  });
});

// Scss task
gulp.task('scss', function () {
  gulp.src('./scss-2017/**/*.scss')
    .pipe(sass())
    // Set specific CSS file
    .pipe(concat('cmb_theme.css'))
    // Set destination directory
    .pipe(gulp.dest('./css'));
});

// Watch task to run on save
gulp.task('default', function () {
  gulp.watch(['scss-2017/**/*.scss'], ['scss']);
  gulp.watch(['patternlab/source/**/**'], ['plab']);
  //gulp.watch(['js/app/*.js', 'js/vendor/*.js'], ['js-vendor']);
});

// Compile everything once
// @todo add better comment
gulp.task('build', function (cb) {
  runSequence(
    'plab',
  cb)
});

// Just incase someone tries to run 'gulp watch' instead of just 'gulp'
gulp.task('watch', ['default']);

// Catch errors instead of crashing (http://maximilianschmitt.me/posts/prevent-gulp-js-from-crashing-on-error/)
function onError(err) {
  console.log(err);
  this.emit('end');
}
