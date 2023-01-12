vim.cmd [[packadd packer.nvim]]
return require('packer').startup(function(use)
    use 'wbthomason/packer.nvim'

    -- telescope
    use {
        'nvim-telescope/telescope.nvim', tag = '0.1.0',
        requires = { {'nvim-lua/plenary.nvim'} }
    }

    -- catppuccin
    use { "catppuccin/nvim", as = "catppuccin" }

    -- treesitter
    use {
        'nvim-treesitter/nvim-treesitter',
        run = ':TSUpdate'
    }

    -- harpoon
    use 'ThePrimeagen/harpoon'

    -- lsp
    use {
        'VonHeikemen/lsp-zero.nvim',
        requires = {
            -- lsp support
            {'neovim/nvim-lspconfig'},
            {'williamboman/mason.nvim'},
            {'williamboman/mason-lspconfig.nvim'},

            -- autocompletion
            {'hrsh7th/nvim-cmp'},
            {'hrsh7th/cmp-buffer'},
            {'hrsh7th/cmp-path'},
            {'saadparwaiz1/cmp_luasnip'},
            {'hrsh7th/cmp-nvim-lsp'},
            {'hrsh7th/cmp-nvim-lua'},

            -- snippets
            {'L3MON4D3/LuaSnip'},
            {'rafamadriz/friendly-snippets'}
        }
    }

    -- lspkind nvim 
    use 'onsails/lspkind.nvim'

    -- lspsaga
    use {
        "glepnir/lspsaga.nvim",
        branch = "main"
    }

    -- autopairs
    use {
        "windwp/nvim-autopairs",
        config = function() require("nvim-autopairs").setup {} end
    }

    -- html autopairs
    use 'windwp/nvim-ts-autotag'

    -- git
    use 'dinhhuy258/git.nvim'

    -- devicons
    use 'nvim-tree/nvim-web-devicons'

    -- git
    use 'lewis6991/gitsigns.nvim'

    -- colorizer
    use 'norcalli/nvim-colorizer.lua'
    require'colorizer'.setup()

    -- zen mode
    use 'folke/zen-mode.nvim'

    -- lua line
    use 'nvim-lualine/lualine.nvim'

    -- alpha
    use 'goolord/alpha-nvim'

    -- jdtls
    use 'mfussenegger/nvim-jdtls'

end)

