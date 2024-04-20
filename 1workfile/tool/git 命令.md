# 1、Local Repository

撤销变更

## git reset   
在本地分支使用，对远程分支无效

	ex : git reset HEAD~1  
	回退到上一个提交记录

## git revert 

	ex : git revert HEAD
	git push -u origin master
	回退到上一个提交，并推送到远程

整理提交
> git rebase -i
> git cherry-pick
> git reset --soft HEAD^   ；撤销了你的commit，写的代码仍然保留

标签tag
git tag v1 c1

git describe 描述里你最近的tag
~~~
`git describe` 的​​语法是：

`git describe <ref>`

`<ref>` 可以是任何能被 Git 识别成提交记录的引用，如果你没有指定的话，Git 会使用你目前所在的位置（`HEAD`）。

它输出的结果是这样的：

`<tag>_<numCommits>_g<hash>`

`tag` 表示的是离 `ref` 最近的标签， `numCommits` 是表示这个 `ref` 与 `tag` 相差有多少个提交记录， `hash` 表示的是你所给定的 `ref` 所表示的提交记录哈希值的前几位。

当 `ref` 提交记录上有某个标签时，则只输出标签名称
~~~
git bisect 找到某个提交记录


# 2、Remote Repository

## 2.1 基本操作(Base Operation)

>git fetch 

向远程仓库传输数据以及从远程仓库获取数据，git fetch 只会从远端下载数据，并不会更新本地的分支，所以还需要通过 `git cherry-pick o/main` 、    `git rebase o/main` 、   `git merge o/main` 、`git pull` 等命令合并到当前的分支。

> git pull

相当于执行了 `git fetch` , `git merge o/main` 命令，`git pull` 命令完成了拉取远程分支并合并的功能。

> git push

推送本地分支到远程

当 git push 执行命令失败时，可以使用以下命令
1. `git fetch` , `git rebase origin` , `git push`
2. `git fetch` , `git merge origin` , `git push`
3. `git pull --rebase` , `git push`
4. `git pull` , `git push`

## 1.2 远程服务器拒绝!(Remote Rejected)

如果你是在一个大的合作团队中工作, 很可能是main被锁定了, 需要一些Pull Request流程来合并修改。如果你直接提交(commit)到本地main, 然后试图推送(push)修改, 你将会收到这样类似的信息:

```
! [远程服务器拒绝] main -> main (TF402455: 不允许推送(push)这个分支; 你必须使用pull request来更新这个分支.)
```

~~~                
为什么会被拒绝？

远程服务器拒绝直接推送(push)提交到main, 因为策略配置要求 pull requests 来提交更新.

你应该按照流程,新建一个分支, 推送(push)这个分支并申请pull request,但是你忘记并直接提交给了main.现在你卡住并且无法推送你的更新.
~~~

~~~     
解决办法。

新建一个分支feature, 推送到远程服务器. 然后reset你的main分支和远程服务器保持一致, 否则下次你pull并且他人的提交和你冲突的时候就会有问题.
~~~

# 3、子模块(Submodules)


If you meat to add a submodules, use:
`git submodules add <url> <path>`

If you added this path by mistask , you can remove it from the index with :
`git rm --cached <path>`

git submodule update --init --recursive
git checkout -b release/v4.4
